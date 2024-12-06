#include "ProjectileBase.h"

AProjectileBase::AProjectileBase(): CollisionComponent(nullptr), ProjectileMovement(nullptr), BaseDamage(0),
                                    ProjectileSpeed(0)
{
}

void AProjectileBase::Initialize(float Damage, float Speed)
{
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectileBase::OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}
