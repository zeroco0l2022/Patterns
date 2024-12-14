#include "SingleFireStrategy.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"

void USingleFireStrategy::Execute(ARangedWeapon* Weapon)
{
	Super::Execute(Weapon);
}

bool USingleFireStrategy::CanExecute(ARangedWeapon* Weapon) const
{
	if (!Weapon)
	{
		return false;
	}

	// Check if weapon has ammo and is not in cooldown
	return true; // Add specific conditions based on weapon state
}
