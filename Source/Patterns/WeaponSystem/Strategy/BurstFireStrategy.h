#pragma once

#include "CoreMinimal.h"
#include "FiringStrategy.h"
#include "BurstFireStrategy.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UBurstFireStrategy : public UFiringStrategy
{
	GENERATED_BODY()

public:
	UBurstFireStrategy();

	virtual void Execute(ARangedWeapon* Weapon) override;
	virtual bool CanExecute(ARangedWeapon* Weapon) const override;
	virtual FString GetStrategyName() const override { return TEXT("Burst Fire"); }

	// Счётчик очередей
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Strategy")
	int32 BurstCount;

	// Задержка между очередями
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Strategy")
	float BurstDelay;

private:
	// Текущая очередь
	int32 CurrentBurst;
	// Таймер очередей
	FTimerHandle BurstTimerHandle;

	// Запуск очередей
	void FireNextBurst(ARangedWeapon* Weapon);
};
