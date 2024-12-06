#include "WeaponPrototype.h"
#include "Patterns/WeaponSystem/Base/WeaponBase.h"
#include "Engine/World.h"

// Создание прототипа оружия, модификация и улучшение

TMap<FString, AWeaponBase*> UWeaponPrototype::WeaponPrototypes;

void UWeaponPrototype::RegisterVariant(const FString& VariantName, AWeaponBase* Prototype)
{
	if (!Prototype)
	{
		return;
	}

	if (WeaponPrototypes.FindRef(VariantName))
	{
		WeaponPrototypes.Remove(VariantName);
	}

	WeaponPrototypes.Add(VariantName, Prototype);
}

AWeaponBase* UWeaponPrototype::CreateFromVariant(const FString& VariantName)
{
	AWeaponBase* Prototype = WeaponPrototypes.FindRef(VariantName);
	if (!Prototype || !Prototype->GetWorld())
	{
		return nullptr;
	}

	return Cast<AWeaponBase>(Prototype->Clone());
}

AWeaponBase* UWeaponPrototype::CreateModifiedWeapon(AWeaponBase* BaseWeapon, float DamageModifier, float RangeModifier,
                                                    const FString& VariantSuffix)
{
	if (!BaseWeapon || !BaseWeapon->GetWorld())
	{
		return nullptr;
	}

	AWeaponBase* ModifiedWeapon = Cast<AWeaponBase>(BaseWeapon->Clone());
	if (!ModifiedWeapon)
	{
		return nullptr;
	}

	ModifiedWeapon->Damage *= DamageModifier;
	ModifiedWeapon->WeaponName = FString::Printf(TEXT("%s_%s"), *BaseWeapon->WeaponName, *VariantSuffix);

	return ModifiedWeapon;
}

AWeaponBase* UWeaponPrototype::CreateUpgradedWeapon(AWeaponBase* BaseWeapon, int32 UpgradeLevel)
{
	if (!BaseWeapon || !BaseWeapon->GetWorld() || UpgradeLevel <= 0)
	{
		return nullptr;
	}

	AWeaponBase* UpgradedWeapon = Cast<AWeaponBase>(BaseWeapon->Clone());
	if (!UpgradedWeapon)
	{
		return nullptr;
	}

	UpgradedWeapon->Damage *= (1.0f + (0.2f * UpgradeLevel));
	UpgradedWeapon->WeaponName = FString::Printf(TEXT("%s_Lvl%d"), *BaseWeapon->WeaponName, UpgradeLevel);

	return UpgradedWeapon;
}

AWeaponBase* UWeaponPrototype::CreateElementalVariant(AWeaponBase* BaseWeapon, const FString& ElementType)
{
	if (!BaseWeapon || !BaseWeapon->GetWorld() || ElementType.IsEmpty())
	{
		return nullptr;
	}

	AWeaponBase* ElementalWeapon = Cast<AWeaponBase>(BaseWeapon->Clone());
	if (!ElementalWeapon)
	{
		return nullptr;
	}

	if (ElementType.Equals(TEXT("Fire"), ESearchCase::IgnoreCase))
	{
		ElementalWeapon->Damage *= 1.3f;
	}
	else if (ElementType.Equals(TEXT("Ice"), ESearchCase::IgnoreCase))
	{
		ElementalWeapon->Damage *= 1.2f;
	}
	else if (ElementType.Equals(TEXT("Lightning"), ESearchCase::IgnoreCase))
	{
		ElementalWeapon->Damage *= 1.4f;
	}

	ElementalWeapon->WeaponName = FString::Printf(TEXT("%s_%s"), *BaseWeapon->WeaponName, *ElementType);
	return ElementalWeapon;
}
