#include "AutoFireStrategy.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"

UAutoFireStrategy::UAutoFireStrategy()
{
}

void UAutoFireStrategy::Execute(ARangedWeapon* Weapon)
{
	if (!Weapon)
	{
		return;
	}

	// Начинаем автоматическую стрельбу
	if (GetWorld())
	{
		// Запускаем таймер
		GetWorld()->GetTimerManager().SetTimer(
			AutoFireTimer,
			[this, Weapon]() { ContinuousFire(Weapon); },
			Weapon->FireRate,
			true
		);
	}
}

void UAutoFireStrategy::ContinuousFire(ARangedWeapon* Weapon)
{
	// Проверяем возможность выполнения, если нет, то прерываем таймер
	if (Weapon && CanExecute(Weapon))
	{
		Super::Execute(Weapon);
	}
	else
	{
		if (Weapon && Weapon->GetWorld())
		{
			Weapon->GetWorld()->GetTimerManager().ClearTimer(AutoFireTimer);
		}
	}
}

bool UAutoFireStrategy::CanExecute(ARangedWeapon* Weapon) const
{
	// Проверяем может ли оружие стрелять в текущем состоянии
	if (!Weapon || !Weapon->GetCurrentState() || !Weapon->GetCurrentState()->CanFire())
	{
		return false;
	}

	return true;
}
