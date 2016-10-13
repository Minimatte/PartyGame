// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PartyPlayerCharacter.h"
#include "PartyGameLib.generated.h"

/**
 *
 */
UCLASS()
class PARTYGAME_API UPartyGameLib : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable, Category = "Colors")
		static FColor GetPlayerColor(int id);
	
		
};
