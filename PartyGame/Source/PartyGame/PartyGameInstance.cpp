// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyGameInstance.h"

bool UPartyGameInstance::AddPlayer(int PlayerID)
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(GWorld->GetLevel(0), PlayerID);


	if (Players.Contains(controller)) {
		Players.Remove(controller);

		//for (int i = 0; i < Score.Num(); i++) {
		//	if (Score[i].Player == PlayerID) {
		//		Score.RemoveAt(i, 1, true);
		//		break;
		//	}
		//}

		return false;
	}
	else {
		FScore s = FScore(PlayerID, 0);
		Players.Add(controller);
		Score.Add(s);
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

int UPartyGameInstance::GetScore(int PlayerID)
{

	for (int i = 0; i < Score.Num(); i++) {
		if (Score[i].Player == PlayerID) {
			return Score[i].Score;
		}
	}

	return 0;
}
