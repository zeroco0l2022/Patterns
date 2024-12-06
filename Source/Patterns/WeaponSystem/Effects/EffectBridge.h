#pragma once

#include "CoreMinimal.h"
#include "EffectBridge.generated.h"


class IEffectImplementation;

UCLASS(Abstract, BlueprintType)
class PATTERNS_API UEffectBridge : public UObject
{
	GENERATED_BODY()

public:
	virtual void Initialize();

	UFUNCTION(BlueprintCallable, Category = "Effects")
	virtual void PlayEffect(const FVector& Location);

	UFUNCTION(BlueprintCallable, Category = "Effects")
	virtual void StopEffect();

protected:
	UPROPERTY()
	TScriptInterface<IEffectImplementation> Implementation;
};
