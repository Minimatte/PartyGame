// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PartyGameGameMode.h"
#include "StopAndGoGameMode.generated.h"

/**
 * 
 */
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EStopAndGo : uint8 {
	VE_Go 		UMETA(DisplayName = "Go"),
	VE_Stop 	UMETA(DisplayName = "Stop"),
	VE_Warning	UMETA(DisplayName = "Warning")
};

UCLASS()
class PARTYGAME_API AStopAndGoGameMode : public APartyGameGameMode
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		EStopAndGo mode;
	
	UFUNCTION(BlueprintCallable, Category = "Stop And Go")
		FColor NextMode();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Stop And Go")
		EStopAndGo GetMode();
	
};
