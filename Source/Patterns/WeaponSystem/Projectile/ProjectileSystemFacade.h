#pragma once

#include "CoreMinimal.h"
#include "ProjectileSystemFacade.generated.h"

class AProjectileBase;
class UEffectBridge;

UCLASS()
class PATTERNS_API UProjectileSystemFacade : public UObject
{
	GENERATED_BODY()

public:
	UProjectileSystemFacade();

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	AProjectileBase* SpawnProjectile(TSubclassOf<AProjectileBase> ProjectileClass,
	                                 const FVector& Location, const FRotator& Rotation,
	                                 float Damage, float Speed);

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void ApplyEffectAtLocation(const FVector& Location,
	                           TSubclassOf<UEffectBridge> EffectClass);

private:
	void InitializeProjectile(AProjectileBase* Projectile, float Damage, float Speed);
	bool ValidateSpawnParameters(TSubclassOf<AProjectileBase> ProjectileClass);
};
