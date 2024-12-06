#include "RangedWeapon.h"
#include "Patterns/WeaponSystem/Projectile/ProjectileBase.h"
#include "Patterns/WeaponSystem//Effects/WeaponEffects.h"

ARangedWeapon::ARangedWeapon()
{
	PrimaryActorTick.bCanEverTick = false;


	AmmoCapacity = 30;
	FireRate = 0.25f;
	ReloadTime = 2.0f;
	bAutomatic = false;
	bCanFire = true;
	ProjectileSpeed = 3000.0f;
}

void ARangedWeapon::BeginPlay()
{
	Super::BeginPlay();

	ProjectileSystem = NewObject<UProjectileSystemFacade>(this);
}

void ARangedWeapon::Fire()
{
	if (!bCanFire || !ProjectileClass)
	{
		return;
	}


	const FTransform MuzzleTransform = GetMuzzleTransform();


	ProjectileSystem->SpawnProjectile(
		ProjectileClass,
		MuzzleTransform.GetLocation(),
		MuzzleTransform.Rotator(),
		Damage,
		ProjectileSpeed
	);


	if (MuzzleEffectClass && ProjectileSystem.IsValid())
	{
		ProjectileSystem->ApplyEffectAtLocation(MuzzleTransform.GetLocation(), MuzzleEffectClass);
	}


	bCanFire = false;
	GetWorld()->GetTimerManager().SetTimer(FireRateTimer, this, &ARangedWeapon::ResetFireRate, FireRate, false);
}

void ARangedWeapon::StartFire()
{
	if (bAutomatic)
	{
		GetWorld()->GetTimerManager().SetTimer(FireRateTimer, this, &ARangedWeapon::Fire, FireRate, true);
	}
	Fire();
}

void ARangedWeapon::StopFire()
{
	if (bAutomatic && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(FireRateTimer);
	}
}

void ARangedWeapon::Reload()
{
	// TODO
}

void ARangedWeapon::ResetFireRate()
{
	bCanFire = true;
}

FTransform ARangedWeapon::GetMuzzleTransform() const
{
	if (WeaponMesh)
	{
		return WeaponMesh->GetSocketTransform(FName("MuzzleSocket"));
	}
	return GetActorTransform();
}


void ARangedWeapon::BeginDestroy()
{
	if (ProjectileSystem.IsValid())
	{
		ProjectileSystem->ConditionalBeginDestroy();
		ProjectileSystem.Reset();
	}

	Super::BeginDestroy();
}
