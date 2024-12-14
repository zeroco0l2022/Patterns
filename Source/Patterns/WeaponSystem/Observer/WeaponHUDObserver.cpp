#include "WeaponHUDObserver.h"
#include "Patterns/WeaponSystem/Base/RangedWeapon.h"


void AWeaponHUDObserver::OnWeaponEvent_Implementation(EWeaponEvent Event, AWeaponBase* Weapon)
{
	if (!Weapon)
	{
		return;
	}

	ARangedWeapon* RangedWeapon = Cast<ARangedWeapon>(Weapon);
	if (!RangedWeapon)
	{
		return;
	}

	switch (Event)
	{
	case EWeaponEvent::Fired:
		UpdateAmmoDisplay(RangedWeapon->CurrentAmmo, RangedWeapon->AmmoCapacity);
		break;
	case EWeaponEvent::Reloaded:
		UpdateAmmoDisplay(RangedWeapon->CurrentAmmo, RangedWeapon->AmmoCapacity);
		break;
	case EWeaponEvent::ChangeFireStrategy:
		UpdateFireStrategy(RangedWeapon);
		break;
	case EWeaponEvent::StateChanged:
		UpdateWeaponState(RangedWeapon->GetCurrentState());
		break;
	}
}

void AWeaponHUDObserver::UpdateAmmoDisplay(int32 AmmoCount, int32 AmmoCapacity)
{
	OnAmmoChanged.Broadcast(AmmoCount, AmmoCapacity);
}


void AWeaponHUDObserver::UpdateFireStrategy(ARangedWeapon* Weapon)
{
	OnStrategyChanged.Broadcast(Weapon->GetCurrentStrategy()->GetStrategyName());
}

void AWeaponHUDObserver::UpdateWeaponState(UWeaponState* WeaponState)
{
	OnStateChanged.Broadcast(WeaponState->GetStateName());
}
