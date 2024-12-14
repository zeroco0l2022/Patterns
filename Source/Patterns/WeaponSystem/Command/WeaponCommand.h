#pragma once

#include "CoreMinimal.h"
#include "WeaponCommand.generated.h"

class AWeaponBase;

UCLASS(Abstract, Blueprintable)
class PATTERNS_API UWeaponCommand : public UObject
{
	GENERATED_BODY()

public:
	// Исполнение команды
	UFUNCTION(BlueprintCallable, Category = "Weapon|Command")
	virtual void Execute() PURE_VIRTUAL(UWeaponCommand::Execute,);

	// Отмена команды
	UFUNCTION(BlueprintCallable, Category = "Weapon|Command")
	virtual void Undo() PURE_VIRTUAL(UWeaponCommand::Undo,);

	// Инициализация оружия
	void Initialize(AWeaponBase* InWeapon) { Weapon = InWeapon; }

protected:
	UPROPERTY()
	AWeaponBase* Weapon;
};
