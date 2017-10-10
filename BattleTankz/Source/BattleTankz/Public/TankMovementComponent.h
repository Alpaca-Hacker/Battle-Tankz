// Copyright P. Gent 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"
class UTankTracks;
/**
 *   Controls Fly-by-Wire functions
 */
UCLASS(ClassGroup = (Tank), meta = (BlueprintSpawnableComponent))
class BATTLETANKZ_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet);
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetForwardIntent(float ForwardIntent) const;
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetRightIntent(float RightIntent) const;

private:
	UTankTracks* LeftTrack = nullptr;
	UTankTracks* RightTrack = nullptr;
};
