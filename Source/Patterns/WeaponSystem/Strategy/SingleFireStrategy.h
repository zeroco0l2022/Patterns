#pragma once

#include "CoreMinimal.h"
#include "FiringStrategy.h"
#include "SingleFireStrategy.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API USingleFireStrategy : public UFiringStrategy
{
	GENERATED_BODY()

public:
	// Выполнение стратегии
	virtual void Execute(ARangedWeapon* Weapon) override;
	// Проверка возможности выполнения
	virtual bool CanExecute(ARangedWeapon* Weapon) const override;
	// Получение названия стратегии
	virtual FString GetStrategyName() const override { return TEXT("Single Fire"); }
};
