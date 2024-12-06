// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PatternsPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class PATTERNS_API APatternsPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface

	virtual void BeginPlay() override;

	// End Actor interface
};
