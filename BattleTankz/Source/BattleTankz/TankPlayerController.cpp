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
	AimTowardsCrosshair();

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



void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}
	FVector HitLocation;
	if (GetSightRayLocation(OUT HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
	}
}

FVector2D ATankPlayerController::GetScreenLocationOfCrossHair() const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);

	return FVector2D(ViewportSizeX*CrossHairLocationX, ViewportSizeY*CrossHairLocationY);
}

bool ATankPlayerController::GetLookDirection(FVector& LookDirection) const
{
	const auto ScreenLocationOfCrossHair = GetScreenLocationOfCrossHair();
	FVector CameraLocation;
	return DeprojectScreenPositionToWorld(ScreenLocationOfCrossHair.X,
	                               ScreenLocationOfCrossHair.Y,
	                               OUT CameraLocation,
	                               OUT LookDirection);
}

bool ATankPlayerController::GetSightRayLocation(FVector& OutHitLocation) const
{
	// Raycast through crosshair
	// Find if intersects landscape
	// if so set OutHitLocation & return true;
	// or return false
	FVector LookDirection;
	GetLookDirection(OUT LookDirection);
	OutHitLocation = LookDirection;
	return true;
}

