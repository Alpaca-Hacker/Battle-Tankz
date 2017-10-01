// Copyright P. Gent 2017

#include "TankPlayerController.h"

void  ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	const auto Tank = GetControlledTank();
	FString TankName = "Unknown";
	if (Tank)
	{
		TankName = Tank->GetName();
	}
	UE_LOG(LogTemp, Warning, TEXT("Player controlling: %s"), *TankName);

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ATank* ATankPlayerController::GetControlledTank() const
{
	const auto ThisTank = GetPawn();
	if (ThisTank)
	{
		return Cast<ATank>(ThisTank);
	}
	UE_LOG(LogTemp, Error, TEXT("Tank Not Found!!"));
	return nullptr;

}

