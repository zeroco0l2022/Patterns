#include "SoundEffectImplementation.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

void USoundEffectImplementation::InitializeImpl()
{
	if (!Sound)
	{
		UE_LOG(LogTemp, Warning, TEXT("SoundEffectImplementation: No sound assigned!"));
	}

	// Set default values if not set
	if (VolumeMultiplier <= 0.0f)
	{
		VolumeMultiplier = 1.0f;
	}
	if (PitchMultiplier <= 0.0f)
	{
		PitchMultiplier = 1.0f;
	}
}

void USoundEffectImplementation::PlayEffectImpl(const FVector& Location)
{
	if (!Sound)
	{
		return;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// Play the sound at the specified location
	ActiveAudioComponent = UGameplayStatics::SpawnSoundAtLocation(
		World,
		Sound,
		Location,
		FRotator::ZeroRotator,
		VolumeMultiplier,
		PitchMultiplier
	);
}

void USoundEffectImplementation::StopEffectImpl()
{
	if (ActiveAudioComponent)
	{
		ActiveAudioComponent->Stop();
		ActiveAudioComponent = nullptr;
	}
}
