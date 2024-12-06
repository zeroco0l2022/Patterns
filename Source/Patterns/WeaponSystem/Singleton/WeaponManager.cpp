#include "WeaponManager.h"

#include "Patterns/WeaponSystem/AbstractFactory/ModernWeaponBuilderFactory.h"
#include "Patterns/WeaponSystem/Base/WeaponBase.h"
#include "Patterns/WeaponSystem/Builder/WeaponBuilder.h"

UWeaponManager* UWeaponManager::Instance = nullptr;

UWeaponManager* UWeaponManager::GetInstance()
{
	if (!Instance)
	{
		Instance = NewObject<UWeaponManager>();
		Instance->AddToRoot();
	}
	return Instance;
}

void UWeaponManager::AddWeaponToInventory(AActor* Pawn, TSubclassOf<UWeaponBuilderFactory> FactoryClass,
                                          TSubclassOf<UWeaponBuilder> BuilderClass)
{
	UWeaponBuilderFactory* Factory = NewObject<UWeaponBuilderFactory>(Pawn, FactoryClass);
	if (Factory)
	{
		if (AWeaponBase* Weapon = Factory->InitializeWeaponBuilder(BuilderClass))
		{
			Inventory.Add(Weapon);
			EquipWeapon(Weapon);
		}
	}
}

void UWeaponManager::RemoveWeaponFromInventory(AWeaponBase* Weapon)
{
	if (Weapon)
	{
		Inventory.Remove(Weapon);
		if (CurrentWeapon == Weapon)
		{
			UnequipCurrentWeapon();
		}
	}
}

void UWeaponManager::EquipWeapon(AWeaponBase* Weapon)
{
	if (!Weapon || !Inventory.Contains(Weapon))
	{
		return;
	}

	UnequipCurrentWeapon();
	CurrentWeapon = Weapon;
	OnWeaponEquipped.Broadcast(CurrentWeapon.Get());
}

void UWeaponManager::UnequipCurrentWeapon()
{
	CurrentWeapon = nullptr;
}
