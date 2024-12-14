#pragma once

#include "CoreMinimal.h"
#include "WeaponObserver.h"
#include "GameFramework/HUD.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"
#include "WeaponHUDObserver.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoChanged, int32, AmmoCount, int32, AmmoCapacity);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStrategyChanged, FString, StrategyName);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateChanged, FString, StateName);

UCLASS()

class PATTERNS_API AWeaponHUDObserver : public AHUD, public IWeaponObserver
{
	GENERATED_BODY()

public:
	virtual void OnWeaponEvent_Implementation(EWeaponEvent Event, AWeaponBase* Weapon) override;

	// Делегат изменения количества патронов
	UPROPERTY(BlueprintAssignable)
	FOnAmmoChanged OnAmmoChanged;
	// Делегат изменения стратегии
	UPROPERTY(BlueprintAssignable)
	FOnStrategyChanged OnStrategyChanged;
	// Делегат изменения состояния
	UPROPERTY(BlueprintAssignable)
	FOnStateChanged OnStateChanged;

protected:
	// Обновление количества патронов
	UFUNCTION(BlueprintCallable)
	void UpdateAmmoDisplay(int32 AmmoCount, int32 AmmoCapacity);

	// Обновление стратегии
	UFUNCTION(BlueprintCallable)
	void UpdateFireStrategy(ARangedWeapon* Weapon);

	// Обновление состояния
	UFUNCTION(BlueprintCallable)
	void UpdateWeaponState(UWeaponState* WeaponState);
};
