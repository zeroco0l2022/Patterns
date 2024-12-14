#pragma once

#include "CoreMinimal.h"
#include "Patterns/WeaponSystem/Base/WeaponBase.h"
#include "WeaponState.generated.h"


UCLASS(Abstract, Blueprintable)
class PATTERNS_API UWeaponState : public UObject
{
	GENERATED_BODY()

public:
	virtual UWeaponState* EnterState(AWeaponBase* Weapon) PURE_VIRTUAL(UWeaponState::EnterState, return nullptr;);
	FORCEINLINE virtual void ExitState(AWeaponBase* Weapon) { BeginDestroy(); };


	virtual bool CanFire() const PURE_VIRTUAL(EWeaponState::CanFire, return false;);
	virtual bool CanReload() const PURE_VIRTUAL(EWeaponState::CanReload, return false;);;
	virtual bool CanSwitch() const PURE_VIRTUAL(EWeaponState::CanSwitch, return false;);;

	virtual void HandleFire() PURE_VIRTUAL(EWeaponState::HandleFire,);;
	virtual void HandleReload() PURE_VIRTUAL(EWeaponState::HandleReload,);

	// Возвращает название состояния
	virtual FString GetStateName() PURE_VIRTUAL(EWeaponState::GetStateName, return "";);

protected:
	UPROPERTY()
	AWeaponBase* CurrentWeapon;
};
