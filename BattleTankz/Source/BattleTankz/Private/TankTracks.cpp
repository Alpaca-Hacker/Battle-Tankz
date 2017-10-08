// Copyright P. Gent 2017

#include "TankTracks.h"


void UTankTracks::SetThrottle(float Throttle)
{
	//TODO: Clamp throttle
	
	UE_LOG(LogTemp, Warning, TEXT("%s throttling: %f"), *GetName(), Throttle );

	const auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	const auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
