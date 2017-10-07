// Copyright P. Gent 2017
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class AProjectile; class UTurret; class UTankBarrel;
class UTankAimingComponent;
UCLASS()
class BATTLETANKZ_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation) const;
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelRef(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretRef(UTurret* TurretToSet) const;
	UFUNCTION(BlueprintCallable, Category = Tank)
	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000.0f;
	UPROPERTY(EditAnywhere, Category = Firing)
	float ReloadTime = 3;
	UPROPERTY(EditAnywhere, Category = Firing)
	TSubclassOf<AProjectile> Projectile;

	UTankBarrel* Barrel = nullptr;
	double LastFireTime = 0;
};
