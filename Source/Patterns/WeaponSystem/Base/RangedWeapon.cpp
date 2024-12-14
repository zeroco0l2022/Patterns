#include "RangedWeapon.h"

#include "Patterns/WeaponSystem/Projectile/ProjectileBase.h"
#include "Patterns/WeaponSystem//Effects/WeaponEffects.h"
#include "Patterns/WeaponSystem/Command/FireWeaponCommand.h"
#include "Patterns/WeaponSystem/Observer/WeaponHUDObserver.h"

#include "Patterns/WeaponSystem/State/FiringState.h"
#include "Patterns/WeaponSystem/State/IdleState.h"
#include "Patterns/WeaponSystem/Visitor/WeaponModificationVisitor.h"

ARangedWeapon::ARangedWeapon()
{
	PrimaryActorTick.bCanEverTick = false;


	AmmoCapacity = 30;
	CurrentAmmo = AmmoCapacity;
	FireRate = 0.25f;
	ReloadTime = 2.0f;
	bAutomatic = false;
	ProjectileSpeed = 3000.0f;
}

void ARangedWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ARangedWeapon::Init()
{
	HUDObserver = NewObject<AWeaponHUDObserver>(this, HUDObserverClass);
	if (HUDObserver)
	{
		HUDObserver->Execute_Init(HUDObserver);
	}

	if (GetOwner())
	{
		ProjectileSystem = NewObject<UProjectileSystemFacade>(GetOwner());
	}

	// Инициализация состояния
	if (DefaultStateClass)
	{
		ChangeState(DefaultStateClass);
	}

	// Инициализация стратегии
	if (DefaultStrategyClass)
	{
		SetFiringStrategy(DefaultStrategyClass);
	}

	if (HUDObserver)
	{
		AddObserver(HUDObserver);
	}
}

void ARangedWeapon::ChangeState(TSubclassOf<UWeaponState> NewStateClass)
{
	if (CurrentState)
	{
		CurrentState->ConditionalBeginDestroy();
	}

	if (NewStateClass)
	{
		CurrentState = NewObject<UWeaponState>(this, NewStateClass);
		CurrentState->EnterState(this);
		NotifyObservers(EWeaponEvent::StateChanged);
	}
}

void ARangedWeapon::SetFiringStrategy(TSubclassOf<UFiringStrategy> NewStrategyClass)
{
	if (NewStrategyClass)
	{
		CurrentStrategy = NewObject<UFiringStrategy>(this, NewStrategyClass);
		NotifyObservers(EWeaponEvent::ChangeFireStrategy);
	}
}

void ARangedWeapon::AddObserver(TScriptInterface<IWeaponObserver> Observer)
{
	if (Observer)
	{
		Observers.AddUnique(Observer);
	}
}

void ARangedWeapon::RemoveObserver(TScriptInterface<IWeaponObserver> Observer)
{
	if (Observer)
	{
		Observers.Remove(Observer);
	}
}

void ARangedWeapon::NotifyObservers(EWeaponEvent Event)
{
	for (const auto& Observer : Observers)
	{
		if (Observer)
		{
			IWeaponObserver::Execute_OnWeaponEvent(Observer.GetObject(), Event, this);
		}
	}
}

void ARangedWeapon::Accept(UWeaponModificationVisitor* Visitor)
{
	if (Visitor)
	{
		Visitor->VisitRangedWeapon(this);
	}
}

void ARangedWeapon::StartFire()
{
	ChangeState(UFiringState::StaticClass());
	if (CurrentStrategy)
	{
		CurrentStrategy->Execute(this);
	}
}

void ARangedWeapon::StopFire()
{
	ChangeState(UIdleState::StaticClass());
}

void ARangedWeapon::Reload()
{
	// TODO
}


FTransform ARangedWeapon::GetMuzzleTransform() const
{
	if (WeaponMesh)
	{
		return WeaponMesh->GetSocketTransform(FName("Muzzle"));
	}
	return GetActorTransform();
}

void ARangedWeapon::BeginDestroy()
{
	if (ProjectileSystem)
	{
		ProjectileSystem->ConditionalBeginDestroy();
		ProjectileSystem = nullptr;
	}

	Super::BeginDestroy();
}
