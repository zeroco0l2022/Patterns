#pragma once

#include "CoreMinimal.h"
#include "WeaponModificationVisitor.h"
#include "Patterns/WeaponSystem/Base/MeleeWeapon.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"
#include "DamageUpgradeVisitor.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UDamageUpgradeVisitor : public UWeaponModificationVisitor
{
	GENERATED_BODY()

public:
	UDamageUpgradeVisitor();

	virtual void VisitRangedWeapon(ARangedWeapon* Weapon) override;
	virtual void VisitMeleeWeapon(AMeleeWeapon* Weapon) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade")
	float DamageMultiplier = 1.15f;
};
