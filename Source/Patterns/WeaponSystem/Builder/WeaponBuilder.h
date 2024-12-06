#pragma once

#include "CoreMinimal.h"
#include "WeaponBuilder.generated.h"

// Универсальный интерфейс для создания оружия

class AWeaponBase;

UCLASS(Abstract, Blueprintable)
class PATTERNS_API UWeaponBuilder : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Weapon|Builder")
	virtual UWeaponBuilder* AddAttachment(const FName& AttachmentPoint, UStaticMesh* AttachmentMesh) PURE_VIRTUAL(
		UWeaponBuilder::AddAttachment, return nullptr;);;

	UFUNCTION(BlueprintCallable, Category = "Weapon|Builder")
	virtual AWeaponBase* Build() PURE_VIRTUAL(UWeaponBuilder::CreateWeapon, return nullptr;);

	UFUNCTION(BlueprintCallable, Category = "Weapon|Builder")
	FORCEINLINE AWeaponBase* GetWeapon() const { return Weapon; }

protected:
	UPROPERTY()
	AWeaponBase* Weapon;
};
