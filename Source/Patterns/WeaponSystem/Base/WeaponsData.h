// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponsData.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Melee,
	Ranged
};

USTRUCT(BlueprintType)
struct FRangeWeaponStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FireRate = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AmmoCapacity = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReloadTime = 3.0f;
};

USTRUCT(BlueprintType)
struct FMeleeWeaponStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SwingSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SwingRange = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StaminaCost = 10.0f;
};
