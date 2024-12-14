#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IWeaponCloneable.h"
#include "WeaponBase.generated.h"


class UWeaponModificationVisitor;
class UWeaponCommandInvoker;
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

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void Init() PURE_VIRTUAL(AWeaponBase::Init,);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	EWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FString WeaponName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	USkeletalMeshComponent* WeaponMesh;

	// Приём посетителя
	UFUNCTION(BlueprintCallable, Category = "Weapon|Visitor")
	virtual void Accept(UWeaponModificationVisitor* Visitor) PURE_VIRTUAL(AWeaponBase::Accept,);

protected:
	// Объект, который будет выполнять команды
	UPROPERTY()
	UWeaponCommandInvoker* CommandInvoker;

	USkeletalMeshComponent* GetWeaponMesh() const { return WeaponMesh; }
};
