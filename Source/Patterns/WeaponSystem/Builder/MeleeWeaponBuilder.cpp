#include "MeleeWeaponBuilder.h"
#include "Patterns/WeaponSystem/Base/MeleeWeapon.h"
#include "Patterns/WeaponSystem/Base/WeaponBase.h"


// Строитель, отвечает за оружия и установку его параметров

AWeaponBase* UMeleeWeaponBuilder::Build()
{
	if (GetWorld())
	{
		//	if (AMeleeWeapon* NewWeapon = GetWorld()->SpawnActor<AMeleeWeapon>())
		//	{
		//		NewWeapon->SwingSpeed = WeaponSettings.SwingSpeed;
		//		NewWeapon->SwingRange = WeaponSettings.SwingRange;
		//		NewWeapon->StaminaCost = WeaponSettings.StaminaCost;
		//		return NewWeapon;
		//	}
	}
	return nullptr;
}
