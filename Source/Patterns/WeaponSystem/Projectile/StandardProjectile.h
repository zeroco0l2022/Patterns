#pragma once

#include "CoreMinimal.h"
#include "ProjectileBase.h"
#include "StandardProjectile.generated.h"

class UEffectBridge;

UCLASS(Blueprintable)
class PATTERNS_API AStandardProjectile : public AProjectileBase
{
	GENERATED_BODY()

public:
	AStandardProjectile();

	virtual void Initialize(float Damage, float Speed) override;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	                                UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	                                const FHitResult& Hit) override;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	TSubclassOf<UEffectBridge> ImpactEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	TSubclassOf<UEffectBridge> TrailEffectClass;

private:
	UPROPERTY()
	TWeakObjectPtr<UEffectBridge> TrailEffect;

	UPROPERTY()
	TWeakObjectPtr<UEffectBridge> ImpactEffect;
};
