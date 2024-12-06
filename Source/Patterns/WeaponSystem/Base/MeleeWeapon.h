#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponsData.h"
#include "MeleeWeapon.generated.h"

class UMeleeSwingEffect;
class UMeleeImpactEffect;
class UProjectileSystemFacade;

UCLASS(Blueprintable)
class PATTERNS_API AMeleeWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	AMeleeWeapon();

	virtual void BeginDestroy() override;

	FMeleeWeaponStats WeaponSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Melee")
	float SwingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Melee")
	float SwingRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Melee")
	float StaminaCost;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Effects")
	TSubclassOf<UMeleeSwingEffect> SwingEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Effects")
	TSubclassOf<UMeleeImpactEffect> ImpactEffectClass;

	UFUNCTION(BlueprintCallable, Category = "Weapon|Melee")
	virtual void Swing();

	UFUNCTION(BlueprintCallable, Category = "Weapon|Melee")
	virtual void Block();

	UFUNCTION(BlueprintCallable, Category = "Weapon|Melee")
	virtual void EndSwing();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                             const FHitResult& SweepResult);

private:
	UPROPERTY()
	TWeakObjectPtr<UProjectileSystemFacade> EffectSystem;

	bool bIsSwinging;
};
