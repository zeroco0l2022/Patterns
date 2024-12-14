#include "StandardProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Patterns/WeaponSystem/Effects/EffectBridge.h"
#include "Engine/DamageEvents.h"

AStandardProjectile::AStandardProjectile()
{
	PrimaryActorTick.bCanEverTick = true;


	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	}

	CollisionComponent->InitSphereRadius(15.0f);
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	CollisionComponent->SetCollisionProfileName(TEXT("Projectile"));
	RootComponent = CollisionComponent;

	if (!ProjectileMovement)
	{
		ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	}
	ProjectileMovement->UpdatedComponent = CollisionComponent;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->InitialSpeed = 5000.0f;
	ProjectileMovement->MaxSpeed = 5000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->ProjectileGravityScale = 0.2f;


	BaseDamage = 20.0f;
	ProjectileSpeed = 5000.0f;
}

void AStandardProjectile::Initialize(float Damage, float Speed)
{
	BaseDamage = Damage;
	ProjectileSpeed = Speed;

	if (ProjectileMovement)
	{
		ProjectileMovement->InitialSpeed = Speed;
		ProjectileMovement->MaxSpeed = Speed;
	}


	if (TrailEffectClass)
	{
		TrailEffect = NewObject<UEffectBridge>(this, TrailEffectClass);
		if (TrailEffect.IsValid())
		{
			TrailEffect->Initialize();
			TrailEffect->PlayEffect(GetActorLocation());
		}
	}
}

void AStandardProjectile::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(3.0f);
	CollisionComponent->OnComponentHit.AddDynamic(this, &AStandardProjectile::OnProjectileImpact);
}


void AStandardProjectile::OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                             UPrimitiveComponent* OtherComp, FVector NormalImpulse,
                                             const FHitResult& Hit)
{
	if (TrailEffect.IsValid())
	{
		TrailEffect->StopEffect();
	}


	if (ImpactEffectClass)
	{
		ImpactEffect = NewObject<UEffectBridge>(this, ImpactEffectClass);
		if (ImpactEffect.IsValid())
		{
			ImpactEffect->Initialize();
			ImpactEffect->PlayEffect(Hit.Location);
		}
	}


	if (OtherActor)
	{
		FDamageEvent DamageEvent;
		OtherActor->TakeDamage(BaseDamage, DamageEvent, GetInstigatorController(), this);
	}


	//Destroy();
}

void AStandardProjectile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (TrailEffect.IsValid())
	{
		TrailEffect->StopEffect();
		TrailEffect->ConditionalBeginDestroy();
		TrailEffect.Reset();
	}

	if (ImpactEffect.IsValid())
	{
		ImpactEffect->StopEffect();
		ImpactEffect->ConditionalBeginDestroy();
		ImpactEffect.Reset();
	}

	Super::EndPlay(EndPlayReason);
}
