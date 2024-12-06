#pragma once

#include "CoreMinimal.h"
#include "Patterns/WeaponSystem/Base/WeaponBase.h"
#include "WeaponBuilderFactory.generated.h"

// Абстрактная фабрика для создания фабрик стрителей оружия

class UWeaponBuilder;

UCLASS(Abstract, Blueprintable)
class PATTERNS_API UWeaponBuilderFactory : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Weapon|Factory")
	virtual AWeaponBase* InitializeWeaponBuilder(const UClass* BuilderClass) PURE_VIRTUAL(
		UWeaponBuilderFactory::CreateRangedWeaponBuilder, return nullptr;);
};
