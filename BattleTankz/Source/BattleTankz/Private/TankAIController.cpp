// Copyright P. Gent 2017

#include "public/TankAIController.h"
#include "Engine/World.h"
#include "public/Tank.h"
#include "TankPlayerController.h"

void  ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Possible pointer errors here, but hey!
	auto ThisTank = Cast<ATank>(GetPawn());
	const auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ThisTank && PlayerTank)
	{
		ThisTank->AimAt(PlayerTank->GetActorLocation());
		ThisTank->Fire();

	}
}



