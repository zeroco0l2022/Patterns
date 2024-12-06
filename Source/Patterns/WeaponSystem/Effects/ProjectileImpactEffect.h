#pragma once

#include "CoreMinimal.h"
#include "CompositeEffect.h"
#include "ProjectileImpactEffect.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UProjectileImpactEffect : public UCompositeEffect
{
	GENERATED_BODY()

public:
	UProjectileImpactEffect();

	virtual void Initialize() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Impact Effect")
	TSubclassOf<UEffectBridge> ParticleEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Impact Effect")
	TSubclassOf<UEffectBridge> SoundEffectClass;

private:
	void CreateAndAddEffect(TSubclassOf<UEffectBridge> EffectClass);
};
