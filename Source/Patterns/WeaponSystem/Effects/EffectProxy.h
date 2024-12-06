#pragma once

#include "CoreMinimal.h"
#include "EffectBridge.h"
#include "EffectProxy.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UEffectProxy : public UEffectBridge
{
	GENERATED_BODY()

public:
	UEffectProxy();

	virtual void Initialize() override;
	virtual void PlayEffect(const FVector& Location) override;
	virtual void StopEffect() override;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	TSubclassOf<UEffectBridge> RealEffectClass;

protected:
	UPROPERTY()
	UEffectBridge* RealEffect;

	void LoadEffectIfNeeded();

private:
	bool bIsLoaded;
};
