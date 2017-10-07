// Copyright P. Gent 2017

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKZ_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairLocationX = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrossHairLocationY = 0.33333;
	UPROPERTY(EditDefaultsOnly)
	float MaxAimDistance = 1000000.0f;

private:
	bool GetLookVectorHitLocation(FVector LookDirectionVector, FVector& OutHitLocation) const;
	bool GetSightRayLocation(FVector& OutHitLocation) const;
	/// Moves barrel towards crosshairs if bullet is going to hit something.
	void AimTowardsCrosshair();
	FVector2D GetScreenLocationOfCrossHair() const;
	bool GetLookDirection(FVector& LookDirection) const;
};
