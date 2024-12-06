#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

UCLASS(Abstract)
class PATTERNS_API AProjectileBase : public AActor
{
	GENERATED_BODY()

public:
	AProjectileBase();

	virtual void Initialize(float Damage, float Speed);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	class USphereComponent* CollisionComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	float BaseDamage;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	float ProjectileSpeed;

	UFUNCTION()
	virtual void OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	                                UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
