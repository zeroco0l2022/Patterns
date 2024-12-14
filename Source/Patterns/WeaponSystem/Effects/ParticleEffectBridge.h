#pragma once

#include "CoreMinimal.h"
#include "EffectBridge.h"
#include "ParticleEffectBridge.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UParticleEffectBridge : public UEffectBridge
{
	GENERATED_BODY()

public:
	virtual void Initialize() override;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	class UNiagaraSystem* ParticleSystem;
};
