#pragma once

#include "CoreMinimal.h"
#include "WeaponObserver.generated.h"

UENUM(BlueprintType)
enum class EWeaponEvent : uint8
{
	// Возможные события наблюдателя
	Fired,
	Reloaded,
	StateChanged,
	ChangeFireStrategy
};

UINTERFACE(MinimalAPI, Blueprintable)
class UWeaponObserver : public UInterface
{
	GENERATED_BODY()
};

class PATTERNS_API IWeaponObserver
{
	GENERATED_BODY()

public:
	// Событие наблюдателя
	UFUNCTION(BlueprintNativeEvent, Category = "Weapon|Observer")
	void OnWeaponEvent(EWeaponEvent Event, class AWeaponBase* Weapon);

	// Инициализация наблюдателя
	UFUNCTION(BlueprintNativeEvent)
	void Init();
};
