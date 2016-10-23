// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "PartyGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FScore
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
		int32 Player;

	UPROPERTY(EditAnywhere)
		int32 Score;

	void SetPlayer(int p) {
		Player = p;
	}

	FScore() {
		Score = 0;
	}

	FScore(int p, int s) {
		Player = p;
		Score = s;
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

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Game Instance")
		int GetScore(int PlayerID);
};
