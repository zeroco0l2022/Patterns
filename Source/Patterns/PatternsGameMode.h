// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PatternsGameMode.generated.h"

UCLASS(minimalapi)
class APatternsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APatternsGameMode();

protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
