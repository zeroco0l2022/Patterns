#include "WeaponPickup.h"
#include "Components/SphereComponent.h"
#include "Patterns/WeaponSystem/Singleton/WeaponManager.h"
#include "WeaponBase.h"
#include "Patterns/WeaponSystem/Builder/WeaponBuilder.h"

AWeaponPickup::AWeaponPickup()
{
	PrimaryActorTick.bCanEverTick = false;

	PickupMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetupAttachment(RootComponent);
	CollisionSphere->SetSphereRadius(100.0f);
	CollisionSphere->SetCollisionProfileName(TEXT("PickUp"));
	CollisionSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AWeaponPickup::OnOverlapBegin);
}

void AWeaponPickup::BeginPlay()
{
	Super::BeginPlay();
}

void AWeaponPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                   const FHitResult& SweepResult)
{
	if (WeaponTimeClass && WeaponTypeClass && OtherActor && UWeaponManager::GetInstance())
	{
		{
			UWeaponManager::GetInstance()->AddWeaponToInventory(OtherActor, WeaponTimeClass, WeaponTypeClass);
			Destroy();
		}
	}
}
