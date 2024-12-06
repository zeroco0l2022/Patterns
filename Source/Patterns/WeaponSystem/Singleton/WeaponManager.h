#pragma once

#include "CoreMinimal.h"
#include "Patterns/WeaponSystem/AbstractFactory/WeaponBuilderFactory.h"
#include "WeaponManager.generated.h"

class AWeaponBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponEquipped, AWeaponBase*, EquippedWeapon);

UCLASS(Blueprintable)
class PATTERNS_API UWeaponManager : public UObject
{
	GENERATED_BODY()

	static UWeaponManager* Instance;

	UPROPERTY()
	TArray<TWeakObjectPtr<AWeaponBase>> Inventory;

	UPROPERTY()
	TWeakObjectPtr<AWeaponBase> CurrentWeapon;

public:
	static UWeaponManager* GetInstance();

	FOnWeaponEquipped OnWeaponEquipped;

	UFUNCTION(BlueprintCallable, Category = "Weapon Management")
	void AddWeaponToInventory(AActor* Pawn, TSubclassOf<UWeaponBuilderFactory> FactoryClass,
	                          TSubclassOf<UWeaponBuilder> BuilderClass);

	UFUNCTION(BlueprintCallable, Category = "Weapon Management")
	void RemoveWeaponFromInventory(AWeaponBase* Weapon);

	UFUNCTION(BlueprintCallable, Category = "Weapon Management")
	void EquipWeapon(AWeaponBase* Weapon);

	UFUNCTION(BlueprintCallable, Category = "Weapon Management")
	void UnequipCurrentWeapon();

	UFUNCTION(BlueprintCallable, Category = "Weapon Management")
	AWeaponBase* GetCurrentWeapon() const { return CurrentWeapon.Get(); }

	UFUNCTION()
	const TArray<TWeakObjectPtr<AWeaponBase>>& GetInventory() const { return Inventory; }
};
