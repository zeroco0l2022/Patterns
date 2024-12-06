#include "ParticleEffectImplementation.h"
#include "NiagaraComponent.h"
#include "NiagaraComponentPoolMethodEnum.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"

void UParticleEffectImplementation::InitializeImpl()
{
	if (!ParticleSystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("ParticleEffectImplementation: No particle system assigned!"));
	}
}

void UParticleEffectImplementation::PlayEffectImpl(const FVector& Location)
{
	if (!ParticleSystem)
	{
		return;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}


	ActiveParticleComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
		World,
		ParticleSystem,
		Location,
		FRotator::ZeroRotator,
		FVector::OneVector,
		true,
		true,
		ENCPoolMethod::AutoRelease,
		true
	);
}

void UParticleEffectImplementation::StopEffectImpl()
{
	if (ActiveParticleComponent)
	{
		ActiveParticleComponent->DeactivateImmediate();
		ActiveParticleComponent = nullptr;
	}
}
