#pragma once

#include "CoreMinimal.h"
#include "WeaponCommand.h"
#include "FireWeaponCommand.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UFireWeaponCommand : public UWeaponCommand
{
	GENERATED_BODY()

public:
	virtual void Execute() override;
};
