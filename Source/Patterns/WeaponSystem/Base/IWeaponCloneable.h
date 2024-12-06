#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IWeaponCloneable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UWeaponCloneable : public UInterface
{
	GENERATED_BODY()
};

class PATTERNS_API IWeaponCloneable
{
	GENERATED_BODY()

public:
	virtual class AWeaponBase* Clone() = 0;
	virtual void CopyPropertiesFrom(const class AWeaponBase* Source) = 0;
};
