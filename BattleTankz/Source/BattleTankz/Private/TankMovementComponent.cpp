// Copyright P. Gent 2017

#include "TankMovementComponent.h"
#include "TankTracks.h"

void UTankMovementComponent::Initialise(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::SetForwardIntent(float ForwardIntent) const
{
	if (!LeftTrack || !RightTrack)
	{
		return;
	}
	LeftTrack->SetThrottle(ForwardIntent);
	RightTrack->SetThrottle(ForwardIntent);
}

void UTankMovementComponent::SetRightIntent(float RightIntent) const
{
	UE_LOG(LogTemp, Warning, TEXT("Throttling: %f"), RightIntent);

	if (!LeftTrack || !RightTrack)
	{
		return;
	}
	LeftTrack->SetThrottle(-RightIntent);
	RightTrack->SetThrottle(RightIntent);
}
