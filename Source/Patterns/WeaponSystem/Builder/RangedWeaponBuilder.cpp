#include "RangedWeaponBuilder.h"
#include "Patterns/WeaponSystem//Base/RangedWeapon.h"
#include "Patterns/WeaponSystem/Base/WeaponBase.h"


// Строитель, отвечает за оружия и установку его параметров

AWeaponBase* URangedWeaponBuilder::Build()
{
	if (GetWorld())
	{
		if (ARangedWeapon* NewWeapon = GetWorld()->SpawnActor<ARangedWeapon>(WeaponClass))
		{
			Weapon = NewWeapon;
			NewWeapon->Damage = WeaponSettings.Damage;
			NewWeapon->FireRate = WeaponSettings.FireRate;
			NewWeapon->AmmoCapacity = WeaponSettings.AmmoCapacity;
			NewWeapon->ReloadTime = WeaponSettings.ReloadTime;
			return NewWeapon;
		}
	}
	return nullptr;
}

UWeaponBuilder* URangedWeaponBuilder::AddAttachment(const FName& AttachmentPoint, UStaticMesh* AttachmentMesh)
{
	if (!Weapon || !AttachmentMesh)
	{
		return this;
	}

	if (UStaticMeshComponent* AttachmentComponent = NewObject<UStaticMeshComponent>(Weapon))
	{
		AttachmentComponent->SetStaticMesh(AttachmentMesh);
		AttachmentComponent->RegisterComponent();
		AttachmentComponent->AttachToComponent(Weapon->GetRootComponent(),
		                                       FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		                                       AttachmentPoint);
	}

	return this;
}
