#pragma once

#include "CoreMinimal.h"
#include "WeaponBuilderFactory.h"
#include "MedievalWeaponBuilderFactory.generated.h"

// Конкретная фабрика для строителя средневекового оружия

UCLASS(Blueprintable)
class PATTERNS_API UMedievalWeaponBuilderFactory : public UWeaponBuilderFactory
{
	GENERATED_BODY()

public:
	virtual AWeaponBase* InitializeWeaponBuilder(const UClass* BuilderClass) override;
};
