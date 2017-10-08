// Copyright P. Gent 2017

#include "TankMovementComponent.h"
#include "TankTracks.h"

void UTankMovementComponent::Initialise(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
	{
		return;
	}
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::SetForwardIntent(float ForwardIntent)
{
	UE_LOG(LogTemp, Warning, TEXT("Throttling: %f"), ForwardIntent);
	if (!LeftTrack || !RightTrack)
	{
		return;
	}
	LeftTrack->SetThrottle(ForwardIntent);
	RightTrack->SetThrottle(ForwardIntent);
}
