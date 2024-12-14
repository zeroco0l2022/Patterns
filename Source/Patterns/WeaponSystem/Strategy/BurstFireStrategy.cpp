#include "BurstFireStrategy.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"

UBurstFireStrategy::UBurstFireStrategy()
{
	BurstCount = 3;
	BurstDelay = 0.1f;
	CurrentBurst = 0;
}

void UBurstFireStrategy::Execute(ARangedWeapon* Weapon)
{
	if (!Weapon || !Weapon->GetWorld())
	{
		return;
	}

	// Обнуляем текущую очередь и запускаем следующую
	CurrentBurst = 0;
	FireNextBurst(Weapon);
}

void UBurstFireStrategy::FireNextBurst(ARangedWeapon* Weapon)
{
	if (!Weapon || CurrentBurst >= BurstCount)
	{
		// Если достигли конца очереди, то прерываем выполнение
		return;
	}

	// Выполнение очередного выстрела
	Super::Execute(Weapon);

	// Увеличиваем счетчик
	CurrentBurst++;

	// Если не достигли конца очереди, то запускаем таймер для следующего выстрела
	if (CurrentBurst < BurstCount && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			BurstTimerHandle,
			[this, Weapon]() { FireNextBurst(Weapon); },
			BurstDelay,
			false
		);
	}
}

bool UBurstFireStrategy::CanExecute(ARangedWeapon* Weapon) const
{
	// Проверка возможности выполнения

	if (!Weapon)
	{
		return false;
	}

	return true;
}
