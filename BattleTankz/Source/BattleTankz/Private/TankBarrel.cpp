// Copyright P. Gent 2017

#include "public/TankBarrel.h"
#include "Engine/World.h"

bool UTankBarrel::Elevate(float RelativeSpeed)
{
	if (RelativeSpeed == 0)
	{
		return false;
	}
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	const auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawElevationChange = RelativeRotation.Pitch + ElevationChange;
	RawElevationChange = FMath::Clamp(RawElevationChange, MinElevation, MaxElevation);
	if (RawElevationChange == MinElevation || RawElevationChange == MaxElevation)
	{
		UE_LOG(LogTemp, Warning, TEXT("Barrel can't move"));
		return false;
	}

	SetRelativeRotation(FRotator(RawElevationChange, 0, 0));
	return true;
}
