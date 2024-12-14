#pragma once

#include "CoreMinimal.h"
#include "FiringStrategy.h"
#include "AutoFireStrategy.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UAutoFireStrategy : public UFiringStrategy
{
	GENERATED_BODY()

public:
	UAutoFireStrategy();

	virtual void Execute(ARangedWeapon* Weapon) override;
	virtual bool CanExecute(ARangedWeapon* Weapon) const override;
	virtual FString GetStrategyName() const override { return TEXT("Automatic Fire"); }

private:
	// Таймер автоматической стрельбы
	FTimerHandle AutoFireTimer;

	// Продолжение автоматической стрельбы
	void ContinuousFire(ARangedWeapon* Weapon);
};
