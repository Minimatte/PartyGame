// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyGameInstance.h"

bool UPartyGameInstance::AddPlayer(int PlayerID)
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(GWorld->GetLevel(0), PlayerID);

	FPartyPlayer player;
	
	player.PlayerID = PlayerID;
	player.Score = 0;


	if (Players.Contains(player)) {
		Players.Remove(player);

		//for (int i = 0; i < Score.Num(); i++) {
		//	if (Score[i].Player == PlayerID) {
		//		Score.RemoveAt(i, 1, true);
		//		break;
		//	}
		//}

		return false;
	}
	else {
		Players.Add(player);
		return true;
	}

	//UGameplayStatics::GetGameMode(GWorld->GetLevel(0))
}

TArray<FPartyPlayer> UPartyGameInstance::GetPlayers()
{
	return Players;
}


