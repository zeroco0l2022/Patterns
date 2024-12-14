#pragma once

#include "CoreMinimal.h"
#include "WeaponState.h"
#include "FiringState.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UFiringState : public UWeaponState
{
	GENERATED_BODY()

public:
	FORCEINLINE virtual UWeaponState* EnterState(AWeaponBase* Weapon) override { return this; }

	// Возвращает true только если для стрельбы
	FORCEINLINE virtual bool CanFire() const override { return true; }
	FORCEINLINE virtual bool CanReload() const override { return false; }
	FORCEINLINE virtual bool CanSwitch() const override { return false; }
	FORCEINLINE virtual FString GetStateName() override { return TEXT("Firing"); }

	virtual void HandleFire() override;

private:
	float FiringTimer;
};
