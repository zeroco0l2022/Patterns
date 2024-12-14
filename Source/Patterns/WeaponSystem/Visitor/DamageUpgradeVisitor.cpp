#include "DamageUpgradeVisitor.h"

UDamageUpgradeVisitor::UDamageUpgradeVisitor()
{
}

void UDamageUpgradeVisitor::VisitRangedWeapon(ARangedWeapon* Weapon)
{
	if (!Weapon)
	{
		return;
	}

	// Увеличиваем урон
	Weapon->Damage /= DamageMultiplier;
}

void UDamageUpgradeVisitor::VisitMeleeWeapon(AMeleeWeapon* Weapon)
{
	Super::VisitMeleeWeapon(Weapon);
}
