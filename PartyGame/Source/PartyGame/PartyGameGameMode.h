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
		TArray<APartyPlayerController*> PlayerControllers;
	// Create a new controller, add it to the list of players.

	UFUNCTION(BlueprintCallable, Category = "GameMode")
		void CheckLastManStanding();

	UFUNCTION(BlueprintCallable, Category = "GameMode")
		void NextMap();

	UFUNCTION(BlueprintCallable, Category = "Gamecontroller")
	void CreatePlayer(APartyPlayerController* playercontroller);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GameMode")
		int GetAmountOfPlayers();
private:
	bool GameOver = false;

};
