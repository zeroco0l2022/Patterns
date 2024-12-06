#pragma once

#include "CoreMinimal.h"
#include "CompositeEffect.h"
#include "WeaponEffects.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API UMuzzleFlashEffect : public UCompositeEffect
{
	GENERATED_BODY()

public:
	UMuzzleFlashEffect();

	virtual void Initialize() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Muzzle Effect")
	TSubclassOf<UEffectBridge> FlashParticleEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Muzzle Effect")
	TSubclassOf<UEffectBridge> SoundEffectClass;
};

UCLASS(Blueprintable)
class PATTERNS_API UMeleeSwingEffect : public UCompositeEffect
{
	GENERATED_BODY()

public:
	UMeleeSwingEffect();

	virtual void Initialize() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Swing Effect")
	TSubclassOf<UEffectBridge> SwingParticleEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Swing Effect")
	TSubclassOf<UEffectBridge> SwingSoundEffectClass;
};

UCLASS(Blueprintable)
class PATTERNS_API UMeleeImpactEffect : public UCompositeEffect
{
	GENERATED_BODY()

public:
	UMeleeImpactEffect();

	virtual void Initialize() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Impact Effect")
	TSubclassOf<UEffectBridge> ImpactParticleEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Impact Effect")
	TSubclassOf<UEffectBridge> ImpactSoundEffectClass;
};
