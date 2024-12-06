#pragma once

#include "CoreMinimal.h"
#include "WeaponBuilderFactory.h"
#include "ModernWeaponBuilderFactory.generated.h"


// Конкретная фабрика для строителя современного оружия

UCLASS(Blueprintable)
class PATTERNS_API UModernWeaponBuilderFactory : public UWeaponBuilderFactory
{
	GENERATED_BODY()

public:
	virtual AWeaponBase* InitializeWeaponBuilder(const UClass* BuilderClass) override;
};
