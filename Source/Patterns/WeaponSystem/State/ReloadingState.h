#pragma once

#include "CoreMinimal.h"
#include "WeaponState.h"
#include "ReloadingState.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UReloadingState : public UWeaponState
{
	GENERATED_BODY()

public:
	virtual UWeaponState* EnterState(AWeaponBase* Weapon) override;

	// В состоянии перезарядки возвращаем все переменные в false
	FORCEINLINE virtual bool CanFire() const override { return false; }
	FORCEINLINE virtual bool CanReload() const override { return false; }
	FORCEINLINE virtual bool CanSwitch() const override { return false; }
	FORCEINLINE virtual FString GetStateName() override { return TEXT("Reloading"); }

private:
	float ReloadTimer;
	void FinishReload();
};
