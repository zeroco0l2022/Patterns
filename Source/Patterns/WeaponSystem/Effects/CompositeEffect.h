#pragma once

#include "CoreMinimal.h"
#include "EffectBridge.h"
#include "CompositeEffect.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UCompositeEffect : public UEffectBridge
{
	GENERATED_BODY()

public:
	virtual void Initialize() override;
	virtual void PlayEffect(const FVector& Location) override;
	virtual void StopEffect() override;

	UFUNCTION(BlueprintCallable, Category = "Effects")
	void AddEffect(UEffectBridge* Effect);

	UFUNCTION(BlueprintCallable, Category = "Effects")
	void RemoveEffect(UEffectBridge* Effect);

protected:
	UPROPERTY()
	TArray<UEffectBridge*> SubEffects;
};
