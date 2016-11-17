// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PartyPlayerController.h"
#include "GameFramework/GameMode.h"
#include "PartyGameGameMode.generated.h"

/**
 *
 */
UCLASS()
class PARTYGAME_API APartyGameGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		float ScoreScreenTime = 5;

	UPROPERTY(EditAnywhere)
		TArray<APartyPlayerController*> PlayerControllers;
	

	//Check for last man standing. Level ends if there is only one player left.
	UFUNCTION(BlueprintCallable, Category = "GameMode")
		bool CheckLastManStanding();

	//Manually win the level for a player. WARNING: USE CAREFULLY.
	UFUNCTION(BlueprintCallable, Category = "GameMode")
		void PlayerWin(APlayerController *playerController);

	//Move to the next map specified in the game instance.
	UFUNCTION(BlueprintCallable, Category = "GameMode")
		void NextMap();

	//Create a new player and add it to the list
	UFUNCTION(BlueprintCallable, Category = "Gamecontroller")
		void CreatePlayer(APartyPlayerController* playercontroller);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GameMode")
		int GetAmountOfPlayers();

	UFUNCTION(BlueprintCallable, Category = "GameMode")
		TArray<AActor*> GetAllSpawnLocations();

	UFUNCTION(BlueprintCallable, Category = "GameMode")
		int GiveScore(int PlayerId);
private:
	bool GameOver = false;

};
