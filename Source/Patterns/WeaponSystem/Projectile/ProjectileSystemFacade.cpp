#include "ProjectileSystemFacade.h"
#include "ProjectileBase.h"
#include "Patterns/WeaponSystem/Effects/EffectBridge.h"

UProjectileSystemFacade::UProjectileSystemFacade()
{
}

AProjectileBase* UProjectileSystemFacade::SpawnProjectile(TSubclassOf<AProjectileBase> ProjectileClass,
                                                          const FVector& Location, const FRotator& Rotation,
                                                          float Damage, float Speed)
{
	if (!ValidateSpawnParameters(ProjectileClass))
	{
		return nullptr;
	}

	if (!GetWorld())
	{
		return nullptr;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AProjectileBase* Projectile = GetWorld()->SpawnActor<AProjectileBase>(
		ProjectileClass,
		Location,
		Rotation,
		SpawnParams
	);

	if (Projectile)
	{
		InitializeProjectile(Projectile, Damage, Speed);
	}

	return Projectile;
}

void UProjectileSystemFacade::ApplyEffectAtLocation(const FVector& Location,
                                                    TSubclassOf<UEffectBridge> EffectClass)
{
	if (!EffectClass)
	{
		return;
	}

	UEffectBridge* Effect = NewObject<UEffectBridge>(this, EffectClass);
	if (Effect)
	{
		Effect->Initialize();
		Effect->PlayEffect(Location);
	}
}

void UProjectileSystemFacade::InitializeProjectile(AProjectileBase* Projectile, float Damage, float Speed)
{
	if (Projectile)
	{
		Projectile->Initialize(Damage, Speed);
	}
}

bool UProjectileSystemFacade::ValidateSpawnParameters(TSubclassOf<AProjectileBase> ProjectileClass)
{
	return ProjectileClass != nullptr;
}
