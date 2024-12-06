#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Patterns/WeaponSystem/AbstractFactory/WeaponBuilderFactory.h"
#include "WeaponPickup.generated.h"

class AWeaponBase;

UCLASS()
class PATTERNS_API AWeaponPickup : public AActor
{
	GENERATED_BODY()

public:
	AWeaponPickup();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<UWeaponBuilderFactory> WeaponTimeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<UWeaponBuilder> WeaponTypeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	USkeletalMeshComponent* PickupMesh;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                            const FHitResult& SweepResult);

protected:
	UPROPERTY()
	class USphereComponent* CollisionSphere;
};
