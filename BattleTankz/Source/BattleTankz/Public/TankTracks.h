// Copyright P. Gent 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 *  Tracks with throttle control
 */
UCLASS(ClassGroup = (Tank), meta = (BlueprintSpawnableComponent))
class BATTLETANKZ_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Set throttle from -1 to +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	UPROPERTY(EditAnywhere, Category = Movement)
	float TrackMaxDrivingForce = 20000000;
	
};
