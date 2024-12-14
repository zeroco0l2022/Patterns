#include "FireRateUpgradeVisitor.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"

UFireRateUpgradeVisitor::UFireRateUpgradeVisitor(): FireRateMultiplier(1.25f)
{
}

void UFireRateUpgradeVisitor::VisitRangedWeapon(ARangedWeapon* Weapon)
{
	if (!Weapon)
	{
		return;
	}

	// Увеличиваем скорость стрельбы
	Weapon->FireRate /= FireRateMultiplier;
	Weapon->StopFire();
}
