#include "ParticleEffectBridge.h"
#include "ParticleEffectImplementation.h"

void UParticleEffectBridge::Initialize()
{
	// Create the implementation
	UParticleEffectImplementation* ParticleImpl = NewObject<UParticleEffectImplementation>(this);
	ParticleImpl->ParticleSystem = ParticleSystem;

	// Set it as our implementation
	Implementation = ParticleImpl;

	// Call parent initialize which will initialize the implementation
	Super::Initialize();
}
