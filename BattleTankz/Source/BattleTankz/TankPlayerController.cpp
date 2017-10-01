// Copyright P. Gent 2017

#include "TankPlayerController.h"

void  ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller wrokign as expected"));

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto Tank = GetControlledTank();
	FString TankName = "Unknown";
	if (Tank)
	{
		TankName = Tank->GetName();
	}
	UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *TankName);
}

ATank* ATankPlayerController::GetControlledTank() const
{
	auto ThisTank = GetPawn();
	if (ThisTank)
	{
		return Cast<ATank>(ThisTank);
	}
	UE_LOG(LogTemp, Error, TEXT("Tank Not Found!!"));
	return nullptr;

}

