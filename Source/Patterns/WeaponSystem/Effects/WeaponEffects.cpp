#include "WeaponEffects.h"
#include "EffectProxy.h"

UMuzzleFlashEffect::UMuzzleFlashEffect()
{
}

void UMuzzleFlashEffect::Initialize()
{
	Super::Initialize();

	if (FlashParticleEffectClass)
	{
		UEffectProxy* ParticleProxy = NewObject<UEffectProxy>(this);
		ParticleProxy->RealEffectClass = FlashParticleEffectClass;
		ParticleProxy->Initialize();
		AddEffect(ParticleProxy);
	}

	if (SoundEffectClass)
	{
		UEffectProxy* SoundProxy = NewObject<UEffectProxy>(this);
		SoundProxy->RealEffectClass = SoundEffectClass;
		SoundProxy->Initialize();
		AddEffect(SoundProxy);
	}
}

UMeleeSwingEffect::UMeleeSwingEffect()
{
}

void UMeleeSwingEffect::Initialize()
{
	Super::Initialize();

	if (SwingParticleEffectClass)
	{
		UEffectProxy* ParticleProxy = NewObject<UEffectProxy>(this);
		ParticleProxy->RealEffectClass = SwingParticleEffectClass;
		ParticleProxy->Initialize();
		AddEffect(ParticleProxy);
	}

	if (SwingSoundEffectClass)
	{
		UEffectProxy* SoundProxy = NewObject<UEffectProxy>(this);
		SoundProxy->RealEffectClass = SwingSoundEffectClass;
		SoundProxy->Initialize();
		AddEffect(SoundProxy);
	}
}

UMeleeImpactEffect::UMeleeImpactEffect()
{
}

void UMeleeImpactEffect::Initialize()
{
	Super::Initialize();

	if (ImpactParticleEffectClass)
	{
		UEffectProxy* ParticleProxy = NewObject<UEffectProxy>(this);
		ParticleProxy->RealEffectClass = ImpactParticleEffectClass;
		ParticleProxy->Initialize();
		AddEffect(ParticleProxy);
	}

	if (ImpactSoundEffectClass)
	{
		UEffectProxy* SoundProxy = NewObject<UEffectProxy>(this);
		SoundProxy->RealEffectClass = ImpactSoundEffectClass;
		SoundProxy->Initialize();
		AddEffect(SoundProxy);
	}
}
