// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PartyGameLib.generated.h"

/**
 *
 */
UCLASS()
class PARTYGAME_API UPartyGameLib : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable, Category = "Colors")
		static FColor GetRandomColor(int id);
	
};
