#pragma once

#include "CoreMinimal.h"
#include "WeaponPrototype.generated.h"

class AWeaponBase;

UCLASS(Blueprintable)
class PATTERNS_API UWeaponPrototype : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Weapon|Prototype")
	static void RegisterVariant(const FString& VariantName, AWeaponBase* Prototype);

	UFUNCTION(BlueprintCallable, Category = "Weapon|Prototype")
	static AWeaponBase* CreateFromVariant(const FString& VariantName);

	UFUNCTION(BlueprintCallable, Category = "Weapon|Prototype")
	static AWeaponBase* CreateModifiedWeapon(AWeaponBase* BaseWeapon, float DamageModifier = 1.0f,
	                                         float RangeModifier = 1.0f, const FString& VariantSuffix = TEXT(""));

	UFUNCTION(BlueprintCallable, Category = "Weapon|Prototype")
	static AWeaponBase* CreateUpgradedWeapon(AWeaponBase* BaseWeapon, int32 UpgradeLevel);

	UFUNCTION(BlueprintCallable, Category = "Weapon|Prototype")
	static AWeaponBase* CreateElementalVariant(AWeaponBase* BaseWeapon, const FString& ElementType);

private:
	static TMap<FString, AWeaponBase*> WeaponPrototypes;
};
