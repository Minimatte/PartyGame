// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PartyPlayerCharacter.h"
#include "PartyGameLib.generated.h"

/**
 *
 */

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EDirectionEnum : uint8 {
	VE_Right 	UMETA(DisplayName = "Right"),
	VE_Left 	UMETA(DisplayName = "Left"),
	VE_Up 		UMETA(DisplayName = "Up"),
	VE_Down		UMETA(DisplayName = "Down")
};

UCLASS()
class PARTYGAME_API UPartyGameLib : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintPure, Category = "Colors")
		static FColor GetPlayerColor(int id);
	
		UFUNCTION(BlueprintPure, Category = "GameMode")
			static AActor* GetPlayerFurthestTo(EDirectionEnum direction);

		UFUNCTION(BlueprintPure, Category = "GameMode")
			static bool IsOnScreen(AActor* Actor, float TimeThreshold);

		UFUNCTION(BlueprintCallable, Category = "Score")
			static void AddScore(int PlayerId);
};
