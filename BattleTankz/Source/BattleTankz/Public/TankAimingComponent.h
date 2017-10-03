// Copyright P. Gent 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
class UTankBarrel; 
//Aims the barrel and turret
UCLASS( ClassGroup=(Tank), meta=(BlueprintSpawnableComponent) )
class BATTLETANKZ_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelRef(UTankBarrel* BarrelToSet);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	float BarrelDirection = 1.0f;
};
