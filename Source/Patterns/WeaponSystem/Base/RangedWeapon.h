#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "Patterns/WeaponSystem/Projectile/ProjectileSystemFacade.h"
#include "Patterns/WeaponSystem/Effects/WeaponEffects.h"
#include "Patterns/WeaponSystem/State/WeaponState.h"
#include "Patterns/WeaponSystem/Strategy/FiringStrategy.h"
#include "Patterns/WeaponSystem/Observer/WeaponObserver.h"
#include "RangedWeapon.generated.h"

class AWeaponHUDObserver;
class UWeaponModificationVisitor;
class UProjectileSystemFacade;

UCLASS(Blueprintable)
class PATTERNS_API ARangedWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	ARangedWeapon();

	virtual void BeginDestroy() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	int32 AmmoCapacity;

	int32 CurrentAmmo = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	float FireRate;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	float ReloadTime;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	bool bAutomatic;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Projectile")
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Projectile")
	float ProjectileSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Effects")
	TSubclassOf<UMuzzleFlashEffect> MuzzleEffectClass;

	// Класс состояния по умолчанию
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|State")
	TSubclassOf<UWeaponState> DefaultStateClass;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void StartFire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void StopFire();

	UFUNCTION(BlueprintCallable, Category = "Weapon|Ranged")
	virtual void Reload();

	UFUNCTION(BlueprintCallable, Category = "Weapon|ProjectileSystem")
	FORCEINLINE UProjectileSystemFacade* GetProjectileSystem() const { return ProjectileSystem; }

	// Переключение состояния
	UFUNCTION(BlueprintCallable, Category = "Weapon|State")
	void ChangeState(TSubclassOf<UWeaponState> NewStateClass);

	// Класс стратегии по умолчанию
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Strategy")
	TSubclassOf<UFiringStrategy> DefaultStrategyClass;

	// Переключение стратегии
	UFUNCTION(BlueprintCallable, Category = "Weapon|Strategy")
	void SetFiringStrategy(TSubclassOf<UFiringStrategy> NewStrategyClass);

	// Добавление/удаление наблюдателей
	UFUNCTION(BlueprintCallable, Category = "Weapon|Observer")
	void AddObserver(TScriptInterface<IWeaponObserver> Observer);

	UFUNCTION(BlueprintCallable, Category = "Weapon|Observer")
	void RemoveObserver(TScriptInterface<IWeaponObserver> Observer);

	// Приём посетителя
	virtual void Accept(UWeaponModificationVisitor* Visitor) override;

	// Уведомление наблюдателей
	void NotifyObservers(EWeaponEvent Event);

	FTransform GetMuzzleTransform() const;

	// Геттеры
	FORCEINLINE UFiringStrategy* GetCurrentStrategy() const { return CurrentStrategy; }
	FORCEINLINE UWeaponState* GetCurrentState() const { return CurrentState; }

protected:
	virtual void BeginPlay() override;
	virtual void Init() override;

	// Текущее состояние
	UPROPERTY()
	UWeaponState* CurrentState;

	// Текущая стратегия
	UPROPERTY()
	UFiringStrategy* CurrentStrategy;

	// Наблюдатели
	UPROPERTY()
	TArray<TScriptInterface<IWeaponObserver>> Observers;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon| Observer")
	TSubclassOf<AWeaponHUDObserver> HUDObserverClass;

	UPROPERTY()
	AWeaponHUDObserver* HUDObserver = nullptr;

	// Приём посетителей
	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Visitor")
	TSubclassOf<UWeaponModificationVisitor> DamageUpgradeVisitorClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Visitor")
	TSubclassOf<UWeaponModificationVisitor> FireRateUpgradeVisitorClass;

private:
	UPROPERTY()
	UProjectileSystemFacade* ProjectileSystem;
};
