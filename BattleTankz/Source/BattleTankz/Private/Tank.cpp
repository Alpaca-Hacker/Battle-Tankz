// Copyright P. Gent 2017
#include "public/Tank.h"
#include "public/TankAimingComponent.h"


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

void ATank::SetBarrelRef(UTankBarrel* BarrelToSet) const
{
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
	UE_LOG(LogTemp, Warning, TEXT("BOOM!!"));
}

