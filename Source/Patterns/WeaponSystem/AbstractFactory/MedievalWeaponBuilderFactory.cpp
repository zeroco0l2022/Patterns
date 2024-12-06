#include "MedievalWeaponBuilderFactory.h"
#include "Patterns/WeaponSystem/Builder/MeleeWeaponBuilder.h"
#include "Patterns/WeaponSystem/Builder/RangedWeaponBuilder.h"


AWeaponBase* UMedievalWeaponBuilderFactory::InitializeWeaponBuilder(const UClass* BuilderClass)
{
	if (GetOuter())
	{
		if (UWeaponBuilder* Builder = NewObject<UWeaponBuilder>(GetOuter(), BuilderClass))
		{
			AWeaponBase* Weapon = Builder->Build();
			return Weapon;
		}
	}
	return nullptr;
}
