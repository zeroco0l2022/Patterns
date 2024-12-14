#pragma once

#include "CoreMinimal.h"
#include "FiringStrategy.generated.h"

class UFireWeaponCommand;
class UWeaponCommandInvoker;
class ARangedWeapon;

UCLASS(Abstract, Blueprintable)
class PATTERNS_API UFiringStrategy : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UWeaponCommandInvoker* CommandInvoker = nullptr;

	UPROPERTY()
	UFireWeaponCommand* FireCommand = nullptr;

	virtual void InitInvoker();

	void InitFireCommand();
	UFUNCTION(BlueprintCallable, Category = "Weapon|Strategy")
	virtual void Execute(ARangedWeapon* Weapon);

	UFUNCTION(BlueprintCallable, Category = "Weapon|Strategy")
	virtual bool CanExecute(ARangedWeapon* Weapon) const PURE_VIRTUAL(UFiringStrategy::CanExecute, return false;);

	UFUNCTION(BlueprintCallable, Category = "Weapon|Strategy")
	virtual FString GetStrategyName() const PURE_VIRTUAL(UFiringStrategy::GetStrategyName, return TEXT(""););
};
