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

	auto ThisTank = GetControlledTank();
	const auto PlayerTank = GetPlayerTank();
	if (ThisTank && PlayerTank)
	{
		ThisTank->AimAt(PlayerTank->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	const auto ThisTank = GetPawn();
	if (ThisTank)
	{
		return Cast<ATank>(ThisTank);
	}
	UE_LOG(LogTemp, Error, TEXT("Tank Not Found!!"));
	return nullptr;

}

ATank* ATankAIController::GetPlayerTank() const
{
	const auto PlayerController= Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
	const auto PlayerTank = PlayerController->GetControlledTank();

	if (PlayerTank)
	{
		return Cast<ATank>(PlayerTank);
	}
	UE_LOG(LogTemp, Error, TEXT("Player Tank Not Found!!"));
	return nullptr;

}


