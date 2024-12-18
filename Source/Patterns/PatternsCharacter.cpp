// Copyright Epic Games, Inc. All Rights Reserved.

#include "PatternsCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "WeaponSystem/Base/RangedWeapon.h"
#include "WeaponSystem/Base/WeaponBase.h"
#include "WeaponSystem/Singleton/WeaponManager.h"
#include "WeaponSystem/Strategy/AutoFireStrategy.h"
#include "WeaponSystem/Strategy/BurstFireStrategy.h"
#include "WeaponSystem/Strategy/SingleFireStrategy.h"
#include "WeaponSystem/Visitor/FireRateUpgradeVisitor.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// APatternsCharacter

APatternsCharacter::APatternsCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));
}

void APatternsCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	if (UWeaponManager::GetInstance())
	{
		UWeaponManager::GetInstance()->OnWeaponEquipped.AddDynamic(this, &APatternsCharacter::OnWeaponEquipped);
	}
}

void APatternsCharacter::OnWeaponEquipped(AWeaponBase* EquippedWeapon)
{
	if (EquippedWeapon && Mesh1P)
	{
		EquippedWeapon->SetOwner(this);
		EquippedWeapon->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true),
		                                  TEXT("GripPoint"));
		EquippedWeapon->Init();
	}
}


//////////////////////////////////////////////////////////////////////////// Input

void APatternsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APatternsCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APatternsCharacter::Look);

		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &APatternsCharacter::Shoot);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Completed, this, &APatternsCharacter::StopShoot);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Canceled, this, &APatternsCharacter::StopShoot);

		EnhancedInputComponent->BindAction(SingleFireAction, ETriggerEvent::Started, this,
		                                   &APatternsCharacter::SwitchToSingleFire);
		EnhancedInputComponent->BindAction(BurstFireAction, ETriggerEvent::Started, this,
		                                   &APatternsCharacter::SwitchToBurstFire);
		EnhancedInputComponent->BindAction(AutoFireAction, ETriggerEvent::Started, this,
		                                   &APatternsCharacter::SwitchToAutoFire);

		EnhancedInputComponent->BindAction(UpgradeWeaponAction, ETriggerEvent::Started, this,
		                                   &APatternsCharacter::UpgradeWeapon);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error,
		       TEXT(
			       "'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."
		       ), *GetNameSafe(this));
	}
}


void APatternsCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void APatternsCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void APatternsCharacter::Shoot()
{
	if (UWeaponManager::GetInstance())
	{
		if (ARangedWeapon* Weapon = Cast<ARangedWeapon>(UWeaponManager::GetInstance()->GetCurrentWeapon()))
		{
			Weapon->StartFire();
		}
	}
}

void APatternsCharacter::StopShoot()
{
	if (UWeaponManager::GetInstance())
	{
		if (ARangedWeapon* Weapon = Cast<ARangedWeapon>(UWeaponManager::GetInstance()->GetCurrentWeapon()))
		{
			Weapon->StopFire();
		}
	}
}

void APatternsCharacter::SwitchToSingleFire()
{
	if (ARangedWeapon* Weapon = Cast<ARangedWeapon>(UWeaponManager::GetInstance()->GetCurrentWeapon()))
	{
		Weapon->SetFiringStrategy(USingleFireStrategy::StaticClass());
	}
}

void APatternsCharacter::SwitchToBurstFire()
{
	if (ARangedWeapon* Weapon = Cast<ARangedWeapon>(UWeaponManager::GetInstance()->GetCurrentWeapon()))
	{
		Weapon->SetFiringStrategy(UBurstFireStrategy::StaticClass());
	}
}

void APatternsCharacter::SwitchToAutoFire()
{
	if (ARangedWeapon* Weapon = Cast<ARangedWeapon>(UWeaponManager::GetInstance()->GetCurrentWeapon()))
	{
		Weapon->SetFiringStrategy(UAutoFireStrategy::StaticClass());
	}
}

void APatternsCharacter::UpgradeWeapon()
{
	if (UWeaponManager::GetInstance())
	{
		UWeaponManager::GetInstance()->UpgradeFireRate(UFireRateUpgradeVisitor::StaticClass());
	}
}
