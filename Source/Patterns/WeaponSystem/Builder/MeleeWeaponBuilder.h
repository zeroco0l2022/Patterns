#pragma once

#include "CoreMinimal.h"
#include "WeaponBuilder.h"
#include "Patterns/WeaponSystem/Base/WeaponsData.h"
#include "MeleeWeaponBuilder.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UMeleeWeaponBuilder : public UWeaponBuilder
{
	GENERATED_BODY()

	FMeleeWeaponStats WeaponSettings;

public:
	virtual AWeaponBase* Build() override;
};
