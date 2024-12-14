#pragma once

#include "CoreMinimal.h"
#include "WeaponCommand.h"
#include "WeaponCommandInvoker.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UWeaponCommandInvoker : public UObject
{
	GENERATED_BODY()

public:
	// Исполнение команд
	UFUNCTION(BlueprintCallable, Category = "Weapon|Command")
	void ExecuteCommand(UWeaponCommand* Command);

	// Отмена последней команды, например, для отмены перезарядки
	UFUNCTION(BlueprintCallable, Category = "Weapon|Command")
	void UndoLastCommand();

	// Очистка истории команд
	UFUNCTION(BlueprintCallable, Category = "Weapon|Command")
	void ClearHistory();

private:
	UPROPERTY()
	TArray<UWeaponCommand*> CommandHistory;
};
