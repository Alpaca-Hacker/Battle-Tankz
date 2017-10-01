// Copyright P. Gent 2017

#include "public/TankAIController.h"
#include "Engine/World.h"
#include "public/Tank.h"
#include "TankPlayerController.h"

void  ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	const auto Tank = GetPlayerTank();
	FString TankName = "Unknown";
	if (Tank)
	{
		TankName = Tank->GetName();
	}
	UE_LOG(LogTemp, Warning, TEXT("AI found player's tank: %s"), *TankName);

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


