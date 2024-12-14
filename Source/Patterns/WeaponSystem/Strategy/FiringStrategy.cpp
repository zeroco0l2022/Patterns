#include "FiringStrategy.h"
#include "Patterns/WeaponSystem/Command/WeaponCommandInvoker.h"
#include "Patterns/WeaponSystem/Command/FireWeaponCommand.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"

void UFiringStrategy::InitInvoker()
{
	// Создаем исполнитель команд
	if (GetOuter())
	{
		CommandInvoker = NewObject<UWeaponCommandInvoker>(GetOuter());
	}
}

void UFiringStrategy::InitFireCommand()
{
	// Создаем команду стрельбы
	if (GetOuter())
	{
		FireCommand = NewObject<UFireWeaponCommand>(GetOuter());
	}
}

void UFiringStrategy::Execute(ARangedWeapon* Weapon)
{
	// Если оружие не создано прекрываем исполнение
	if (!Weapon)
	{
		return;
	}

	// Если исполнитель команд не создан инициализируем
	if (!CommandInvoker)
	{
		InitInvoker();
	}

	// Если команда стрельбы не создана инициализируем
	if (!FireCommand)
	{
		InitFireCommand();
	}

	// Инициализируем оружие в команде стрельбы
	FireCommand->Initialize(Weapon);

	// Выполняем команду
	CommandInvoker->ExecuteCommand(FireCommand);
}
