#pragma once

#include "CoreMinimal.h"
#include "WeaponCommand.h"
#include "ReloadWeaponCommand.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UReloadWeaponCommand : public UWeaponCommand
{
	GENERATED_BODY()

public:
	virtual void Execute() override;
	virtual void Undo() override;

private:
	int32 PreviousAmmoCount;
};
