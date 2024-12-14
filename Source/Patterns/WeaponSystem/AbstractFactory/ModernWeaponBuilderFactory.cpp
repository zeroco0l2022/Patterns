#include "ModernWeaponBuilderFactory.h"
#include "Patterns/WeaponSystem/Builder/MeleeWeaponBuilder.h"
#include "Patterns/WeaponSystem/Builder/RangedWeaponBuilder.h"


AWeaponBase* UModernWeaponBuilderFactory::InitializeWeaponBuilder(const UClass* BuilderClass)
{
	if (GetOuter())
	{
		if (UWeaponBuilder* Builder = NewObject<UWeaponBuilder>(GetOuter(), BuilderClass))
		{
			AWeaponBase* Weapon = Builder->Build();
			if (UStaticMesh* AttachmentMesh = LoadObject<UStaticMesh>(
				nullptr, TEXT("/Script/Engine.StaticMesh'/Game/FPWeapon/Mesh/Scope.Scope'")))
			{
				Builder->AddAttachment("Scope", AttachmentMesh);
			}
			return Weapon;
		}
	}
	return nullptr;
}
