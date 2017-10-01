// Copyright P. Gent 2017

#pragma once
#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKZ_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

};
