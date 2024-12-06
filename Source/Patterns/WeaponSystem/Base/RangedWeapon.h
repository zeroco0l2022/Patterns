#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "Patterns/WeaponSystem/Projectile/ProjectileSystemFacade.h"
#include "Patterns/WeaponSystem/Effects/WeaponEffects.h"
#include "RangedWeapon.generated.h"


UCLASS(Blueprintable)
class PATTERNS_API ARangedWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	ARangedWeapon();

	virtual void BeginDestroy() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	int32 AmmoCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	float FireRate;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	float ReloadTime;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	bool bAutomatic;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Projectile")
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Projectile")
	float ProjectileSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Effects")
	TSubclassOf<UMuzzleFlashEffect> MuzzleEffectClass;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void StartFire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void StopFire();

	UFUNCTION(BlueprintCallable, Category = "Weapon|Ranged")
	virtual void Reload();

protected:
	virtual void BeginPlay() override;

private:
	bool bCanFire;
	FTimerHandle FireRateTimer;

	UPROPERTY()
	TWeakObjectPtr<UProjectileSystemFacade> ProjectileSystem;

	void ResetFireRate();
	FTransform GetMuzzleTransform() const;
};
