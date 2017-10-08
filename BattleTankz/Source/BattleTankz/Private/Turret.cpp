// Copyright P. Gent 2017

#include "Turret.h"
#include "Engine/World.h"

bool UTurret::Rotate(float RelativeSpeed)
{
	if (RelativeSpeed == 0)
	{
		return false;
	}
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	const auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	const auto RawRotationChange = RelativeRotation.Yaw + RotationChange;
	//RawElevationChange = FMath::Clamp(RawElevationChange, MinElevation, MaxElevation);
	if (RawRotationChange == 0)
	{
		return false;
	}
	//UE_LOG(LogTemp, Warning, TEXT("Turret wants to move %f"), RelativeSpeed);
	SetRelativeRotation(FRotator(0, RawRotationChange, 0));
	return true;

}
