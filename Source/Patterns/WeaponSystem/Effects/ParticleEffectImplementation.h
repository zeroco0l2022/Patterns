#pragma once

#include "CoreMinimal.h"
#include "IEffectImplementation.h"
#include "ParticleEffectImplementation.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UParticleEffectImplementation : public UObject, public IEffectImplementation
{
	GENERATED_BODY()

public:
	virtual void PlayEffectImpl(const FVector& Location) override;
	virtual void StopEffectImpl() override;
	virtual void InitializeImpl() override;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	class UNiagaraSystem* ParticleSystem;

protected:
	UPROPERTY()
	class UNiagaraComponent* ActiveParticleComponent;
};
