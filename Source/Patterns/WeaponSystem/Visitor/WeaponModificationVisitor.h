#pragma once

#include "CoreMinimal.h"
#include "Patterns/WeaponSystem/Base/MeleeWeapon.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"
#include "WeaponModificationVisitor.generated.h"


UCLASS(Abstract, Blueprintable)
class PATTERNS_API UWeaponModificationVisitor : public UObject
{
	GENERATED_BODY()

public:
	// Поститель посещает конкретные типы оружия
	UFUNCTION(BlueprintCallable, Category = "Weapon|Modification")
	virtual void VisitRangedWeapon(ARangedWeapon* Weapon) PURE_VIRTUAL(UWeaponModificationVisitor::VisitRangedWeapon,);

	UFUNCTION(BlueprintCallable, Category = "Weapon|Modification")
	virtual void VisitMeleeWeapon(AMeleeWeapon* Weapon) PURE_VIRTUAL(UWeaponModificationVisitor::VisitMeleeWeapon,);
};
