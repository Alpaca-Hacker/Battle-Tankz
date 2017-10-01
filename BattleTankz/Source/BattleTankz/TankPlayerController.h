// Copyright P. Gent 2017

#pragma once
#include "CoreMinimal.h"
#include "public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKZ_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;
	
	
};
