#include "EffectProxy.h"

UEffectProxy::UEffectProxy()
	: RealEffect(nullptr)
	  , bIsLoaded(false)
{
}

void UEffectProxy::Initialize()
{
}

void UEffectProxy::PlayEffect(const FVector& Location)
{
	LoadEffectIfNeeded();

	if (RealEffect)
	{
		RealEffect->PlayEffect(Location);
	}
}

void UEffectProxy::StopEffect()
{
	if (RealEffect)
	{
		RealEffect->StopEffect();
	}
}

void UEffectProxy::LoadEffectIfNeeded()
{
	if (!bIsLoaded && RealEffectClass)
	{
		RealEffect = NewObject<UEffectBridge>(this, RealEffectClass);
		if (RealEffect)
		{
			RealEffect->Initialize();
			bIsLoaded = true;
		}
	}
}
