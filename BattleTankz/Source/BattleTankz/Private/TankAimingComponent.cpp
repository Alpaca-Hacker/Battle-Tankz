// Copyright P. Gent 2017

#include "public/TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Turret.h"
#include "public/TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel || !Turret)
	{
		return;
	}
	auto Name = GetOwner()->GetName();
	
	FVector OutLaunchVelocity;
	const auto StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	auto Hit = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUT OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.0f,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		//FCollisionResponseParams::DefaultResponseParam,
		//TArray<AActor*>(),
		//true
	);

	if (Hit)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;

	auto bBarrelMoved = Barrel->Elevate(DeltaRotator.Pitch);
	auto bTurretMoved = Turret->Rotate(DeltaRotator.Yaw);
}


void UTankAimingComponent::SetBarrelRef(UTankBarrel* BarrelToSet)
{
	if (BarrelToSet)
	{
		Barrel = BarrelToSet;
	}
}

void UTankAimingComponent::SetTurretRef(UTurret* TurretToSet)
{
	Turret = TurretToSet;
}

