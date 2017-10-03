// Copyright P. Gent 2017

#include "Turret.h"


bool UTurret::Rotate(float RelativeSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Turret wants to move %f"), RelativeSpeed);
	return false;
}
