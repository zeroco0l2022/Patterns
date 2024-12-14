#pragma once

#include "CoreMinimal.h"
#include "WeaponState.h"
#include "IdleState.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UIdleState : public UWeaponState
{
	GENERATED_BODY()

public:
	virtual UWeaponState* EnterState(AWeaponBase* Weapon) override;

	// В состоянии покоя нельзя стрелять
	FORCEINLINE virtual bool CanFire() const override { return false; }
	FORCEINLINE virtual bool CanReload() const override { return true; }
	FORCEINLINE virtual bool CanSwitch() const override { return true; }

	FORCEINLINE virtual FString GetStateName() override { return TEXT("Idle"); }
};
