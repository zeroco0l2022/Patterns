#include "ReloadWeaponCommand.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"

void UReloadWeaponCommand::Execute()
{
	if (ARangedWeapon* RangedWeapon = Cast<ARangedWeapon>(Weapon))
	{
		PreviousAmmoCount = RangedWeapon->AmmoCapacity;
		// Сохраняем предыдущее количество патронов на случай отмены команды
		RangedWeapon->Reload();
	}
}

void UReloadWeaponCommand::Undo()
{
	if (ARangedWeapon* RangedWeapon = Cast<ARangedWeapon>(Weapon))
	{
		// Возвращаем предыдущее количество патронов
		RangedWeapon->AmmoCapacity = PreviousAmmoCount;
	}
}
