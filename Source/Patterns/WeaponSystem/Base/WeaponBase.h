#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IWeaponCloneable.h"
#include "WeaponBase.generated.h"


enum class EWeaponType : uint8;

UCLASS(Abstract)
class PATTERNS_API AWeaponBase : public AActor, public IWeaponCloneable
{
	GENERATED_BODY()

public:
	AWeaponBase();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual AWeaponBase* Clone() override;
	virtual void CopyPropertiesFrom(const AWeaponBase* Source) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	EWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FString WeaponName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	USkeletalMeshComponent* WeaponMesh;

protected:
	USkeletalMeshComponent* GetWeaponMesh() const { return WeaponMesh; }
};
