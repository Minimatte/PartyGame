// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyGameInstance.h"

bool UPartyGameInstance::AddPlayer(int PlayerID)
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(GWorld->GetLevel(0), PlayerID);
	FScore s;
	s.Player = controller;
	s.Score = 0;

	if (Players.Contains(controller)) {
		Players.Remove(controller);

	
		return false;
	}else{
		Players.Add(controller);
	
		return true;
	}

	//UGameplayStatics::GetGameMode(GWorld->GetLevel(0))
}

TArray<APlayerController*> UPartyGameInstance::GetPlayers()
{
	return Players;
}

TArray<FScore> UPartyGameInstance::GetScoreList()
{
	return Score;
}
