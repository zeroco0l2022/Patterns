#include "CompositeEffect.h"

void UCompositeEffect::Initialize()
{
	Super::Initialize();

	for (UEffectBridge* Effect : SubEffects)
	{
		if (Effect)
		{
			Effect->Initialize();
		}
	}
}

void UCompositeEffect::PlayEffect(const FVector& Location)
{
	for (UEffectBridge* Effect : SubEffects)
	{
		if (Effect)
		{
			Effect->PlayEffect(Location);
		}
	}
}

void UCompositeEffect::StopEffect()
{
	for (UEffectBridge* Effect : SubEffects)
	{
		if (Effect)
		{
			Effect->StopEffect();
		}
	}
}

void UCompositeEffect::AddEffect(UEffectBridge* Effect)
{
	if (Effect)
	{
		SubEffects.AddUnique(Effect);
	}
}

void UCompositeEffect::RemoveEffect(UEffectBridge* Effect)
{
	if (Effect)
	{
		SubEffects.Remove(Effect);
	}
}
