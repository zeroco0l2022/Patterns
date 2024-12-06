#include "MeleeWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Patterns/WeaponSystem/Projectile/ProjectileSystemFacade.h"
#include "Engine/DamageEvents.h"
#include "Patterns/WeaponSystem/Effects/WeaponEffects.h"

AMeleeWeapon::AMeleeWeapon()
{
	PrimaryActorTick.bCanEverTick = true;


	SwingSpeed = 1.0f;
	SwingRange = 200.0f;
	StaminaCost = 20.0f;
	bIsSwinging = false;
}

void AMeleeWeapon::BeginPlay()
{
	Super::BeginPlay();


	EffectSystem = NewObject<UProjectileSystemFacade>(this);

	if (WeaponMesh)
	{
		WeaponMesh->OnComponentBeginOverlap.AddDynamic(this, &AMeleeWeapon::OnWeaponOverlap);
	}
}

void AMeleeWeapon::Swing()
{
	if (bIsSwinging)
	{
		return;
	}

	bIsSwinging = true;

	if (SwingEffectClass && EffectSystem.IsValid())
	{
		EffectSystem->ApplyEffectAtLocation(GetActorLocation(), SwingEffectClass);
	}
}

void AMeleeWeapon::EndSwing()
{
	bIsSwinging = false;
}

void AMeleeWeapon::Block()
{
	// TODO
}

void AMeleeWeapon::OnWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                   const FHitResult& SweepResult)
{
	if (!bIsSwinging || !OtherActor || OtherActor == GetOwner())
	{
		return;
	}


	const FDamageEvent DamageEvent;
	OtherActor->TakeDamage(WeaponSettings.Damage, DamageEvent, GetInstigatorController(), this);


	if (ImpactEffectClass && EffectSystem.IsValid())
	{
		EffectSystem->ApplyEffectAtLocation(SweepResult.ImpactPoint, ImpactEffectClass);
	}
}


void AMeleeWeapon::BeginDestroy()
{
	if (EffectSystem.IsValid())
	{
		EffectSystem->ConditionalBeginDestroy();
		EffectSystem.Reset();
	}

	Super::BeginDestroy();
}
