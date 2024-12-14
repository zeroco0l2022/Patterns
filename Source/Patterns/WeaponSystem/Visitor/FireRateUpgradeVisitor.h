#pragma once

#include "CoreMinimal.h"
#include "WeaponModificationVisitor.h"
#include "FireRateUpgradeVisitor.generated.h"


class ARangedWeapon;

UCLASS(Blueprintable)
class PATTERNS_API UFireRateUpgradeVisitor : public UWeaponModificationVisitor
{
	GENERATED_BODY()

public:
	UFireRateUpgradeVisitor();

	virtual void VisitRangedWeapon(ARangedWeapon* Weapon) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Upgrade")
	float FireRateMultiplier;
};
