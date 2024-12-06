#include "ProjectileImpactEffect.h"
#include "EffectProxy.h"

UProjectileImpactEffect::UProjectileImpactEffect()
{
}

void UProjectileImpactEffect::Initialize()
{
	Super::Initialize();

	// Create and add particle effect using proxy for lazy loading
	CreateAndAddEffect(ParticleEffectClass);
	CreateAndAddEffect(SoundEffectClass);
}

void UProjectileImpactEffect::CreateAndAddEffect(TSubclassOf<UEffectBridge> EffectClass)
{
	if (EffectClass)
	{
		// Create a proxy for lazy loading of the effect
		if (UEffectProxy* EffectProxy = NewObject<UEffectProxy>(this))
		{
			EffectProxy->RealEffectClass = EffectClass;
			EffectProxy->Initialize();
			AddEffect(EffectProxy);
		}
	}
}
