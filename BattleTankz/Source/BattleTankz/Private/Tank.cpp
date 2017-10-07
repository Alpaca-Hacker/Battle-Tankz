// Copyright P. Gent 2017
#include "public/Tank.h"
#include "public/TankAimingComponent.h"
#include "Engine/World.h"
#include "public/TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation) const
{
	if (TankAimingComponent)
	{
		TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	}
}

void ATank::SetBarrelRef(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
	if (TankAimingComponent)
	{
		TankAimingComponent->SetBarrelRef(BarrelToSet);
	}
}

void ATank::SetTurretRef(UTurret* TurretToSet) const
{
	if (TankAimingComponent)
	{
		TankAimingComponent->SetTurretRef(TurretToSet);
	}
}

void ATank::Fire()
{
	const auto IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (Projectile && Barrel && IsReloaded)
	{
		const auto SpawnPoint = Barrel->GetSocketLocation(FName("Projectile"));
		const auto SpawnRotation = Barrel->GetSocketRotation(FName("Projectile"));
		const auto Bullet = GetWorld()->SpawnActor<AProjectile>(Projectile, SpawnPoint, SpawnRotation);
		Bullet->FireProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

