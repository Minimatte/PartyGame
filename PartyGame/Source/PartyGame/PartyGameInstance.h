// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "PartyPlayerController.h"
#include "PartyGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FPartyPlayer
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite)
		int32 PlayerID;

	UPROPERTY(EditAnywhere)
		int32 Score;

	void SetPlayer(int p) {
		PlayerID = p;
	}

	FPartyPlayer() {
		Score = 0;
	}

	FPartyPlayer(int p, int s) {
		PlayerID = p;
		Score = s;
	}

	friend bool operator==(const FPartyPlayer &lhs, const FPartyPlayer &rhs) {
		return (lhs.PlayerID == rhs.PlayerID);
	}
};



UCLASS(BlueprintType, Blueprintable)
class PARTYGAME_API UPartyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere)
		FName NextMap = "Level_Platforms";

	UPROPERTY(EditAnywhere)
		TMap<int, FPartyPlayer> PlayerList;

	UPROPERTY(EditAnywhere)
		TArray<FPartyPlayer> Players;

	UPROPERTY(EditAnywhere)
		TArray<FName> Levels;

	UPROPERTY(EditAnywhere)
		int RequiredWins = 1;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Game Instance")
		int GetRequiredWins();

	UFUNCTION(BlueprintCallable, Category = "Party Game Instance")
		void SetRequiredWins(int wins);

	UFUNCTION(BlueprintCallable, Category = "Party Game Instance")
		void SetLevelList(TArray<FName> levelnames);

	UFUNCTION(BlueprintCallable, Category = "Party Game Instance")
		bool AddPlayer(int PlayerID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Game Instance")
		TArray<FPartyPlayer> GetPlayers();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Game Instance")
		FPartyPlayer GetPlayer(int PlayerControllerID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Game Instance")
		int IndexOfPlayer(int PlayerID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Game Instance")
		FPartyPlayer GetLeadingPlayer();
};
