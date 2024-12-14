#include "FireWeaponCommand.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"

void UFireWeaponCommand::Execute()
{
	if (ARangedWeapon* RangedWeapon = Cast<ARangedWeapon>(Weapon))
	{
		RangedWeapon->NotifyObservers(EWeaponEvent::Fired);

		const FTransform MuzzleTransform = RangedWeapon->GetMuzzleTransform();

		RangedWeapon->GetProjectileSystem()->SpawnProjectile(
			RangedWeapon->ProjectileClass,
			MuzzleTransform.GetLocation(),
			MuzzleTransform.Rotator(),
			RangedWeapon->Damage,
			RangedWeapon->ProjectileSpeed
		);

		if (RangedWeapon->MuzzleEffectClass && RangedWeapon->GetProjectileSystem())
		{
			RangedWeapon->GetProjectileSystem()->ApplyEffectAtLocation(MuzzleTransform.GetLocation(),
			                                                           RangedWeapon->MuzzleEffectClass);
		}
	}
}
