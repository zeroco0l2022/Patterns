#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEffectImplementation.generated.h"

UINTERFACE(MinimalAPI)
class UEffectImplementation : public UInterface
{
	GENERATED_BODY()
};

class PATTERNS_API IEffectImplementation
{
	GENERATED_BODY()

public:
	virtual void PlayEffectImpl(const FVector& Location) = 0;
	virtual void StopEffectImpl() = 0;
	virtual void InitializeImpl() = 0;
};
