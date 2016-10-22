// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "PartyGameInstance.generated.h"

USTRUCT()
struct FScore
{
	GENERATED_BODY()

	UPROPERTY()
		APlayerController* Player;

	UPROPERTY()
		int Score;

	void SetPlayer(APlayerController* p) {
		Player = p;
	}

	FScore() {
		Score = 0;
	}

};

UCLASS(BlueprintType, Blueprintable)
class PARTYGAME_API UPartyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		TArray<APlayerController*> Players;
	
	UPROPERTY(EditAnywhere)
		TArray<FString> Levels;

	UPROPERTY(EditAnywhere)
		TArray<FScore> Score;
	
	UFUNCTION(BlueprintCallable, Category = "Party Game Instance")
		bool AddPlayer(int PlayerID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Game Instance")
		TArray<APlayerController*> GetPlayers();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Game Instance")
		TArray<FScore> GetScoreList();
};
