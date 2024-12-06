#include "EffectBridge.h"
#include "IEffectImplementation.h"

void UEffectBridge::Initialize()
{
	if (Implementation)
	{
		Implementation->InitializeImpl();
	}
}

void UEffectBridge::PlayEffect(const FVector& Location)
{
	if (Implementation)
	{
		Implementation->PlayEffectImpl(Location);
	}
}

void UEffectBridge::StopEffect()
{
	if (Implementation)
	{
		Implementation->StopEffectImpl();
	}
}
