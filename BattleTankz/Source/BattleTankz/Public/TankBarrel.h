// Copyright P. Gent 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Tank), meta = (BlueprintSpawnableComponent))
class BATTLETANKZ_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	bool Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0.0f;
};
