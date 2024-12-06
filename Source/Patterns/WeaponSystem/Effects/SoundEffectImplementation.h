#pragma once

#include "CoreMinimal.h"
#include "IEffectImplementation.h"
#include "SoundEffectImplementation.generated.h"

UCLASS(Blueprintable)
class PATTERNS_API USoundEffectImplementation : public UObject, public IEffectImplementation
{
	GENERATED_BODY()

public:
	virtual void PlayEffectImpl(const FVector& Location) override;
	virtual void StopEffectImpl() override;
	virtual void InitializeImpl() override;

	UPROPERTY(EditDefaultsOnly, Category = "Sound Effect")
	USoundBase* Sound;

	UPROPERTY(EditDefaultsOnly, Category = "Sound Effect")
	float VolumeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category = "Sound Effect")
	float PitchMultiplier;

protected:
	UPROPERTY()
	UAudioComponent* ActiveAudioComponent;
};
