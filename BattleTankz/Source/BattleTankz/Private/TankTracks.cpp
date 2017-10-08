// Copyright P. Gent 2017

#include "TankTracks.h"


void UTankTracks::SetThrottle(float Throttle)
{
	//TODO: Clamp throttle	

	const auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	const auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
