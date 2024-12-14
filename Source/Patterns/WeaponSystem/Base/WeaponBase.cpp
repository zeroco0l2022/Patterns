#include "WeaponBase.h"
#include "WeaponsData.h"
#include "Patterns/WeaponSystem/Projectile/ProjectileSystemFacade.h"
#include "Patterns/WeaponSystem/Command/WeaponCommandInvoker.h"


AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false; // No need for tick without effects

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;
	WeaponMesh->SetCollisionResponseToAllChannels(ECR_Ignore);

	Damage = 10.0f;
	WeaponType = EWeaponType::Melee;
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	// Создаем объект для исполнения команд
	CommandInvoker = NewObject<UWeaponCommandInvoker>(this);
}

void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AWeaponBase* AWeaponBase::Clone()
{
	if (!GetWorld())
	{
		return nullptr;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.Template = this;

	AWeaponBase* ClonedWeapon = GetWorld()->SpawnActor<AWeaponBase>(
		GetClass(),
		GetActorLocation(),
		GetActorRotation(),
		SpawnParams
	);

	if (ClonedWeapon)
	{
		ClonedWeapon->CopyPropertiesFrom(this);
	}

	return ClonedWeapon;
}

void AWeaponBase::CopyPropertiesFrom(const AWeaponBase* Source)
{
	if (!Source)
	{
		return;
	}

	WeaponName = Source->WeaponName;
	Damage = Source->Damage;
	WeaponType = Source->WeaponType;

	if (WeaponMesh && Source->WeaponMesh)
	{
		WeaponMesh->SetSkeletalMesh(Source->WeaponMesh->GetSkeletalMeshAsset());
	}
}
