#pragma once

#include "CoreMinimal.h"
#include "WeaponBuilder.h"
#include "Patterns/WeaponSystem/Base/WeaponsData.h"
#include "RangedWeaponBuilder.generated.h"

class ARangedWeapon;

UCLASS(Blueprintable)
class PATTERNS_API URangedWeaponBuilder : public UWeaponBuilder
{
	GENERATED_BODY()

	FRangeWeaponStats WeaponSettings;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<ARangedWeapon> WeaponClass;

public:
	virtual AWeaponBase* Build() override;
	virtual UWeaponBuilder* AddAttachment(const FName& AttachmentPoint, UStaticMesh* AttachmentMesh) override;
};
