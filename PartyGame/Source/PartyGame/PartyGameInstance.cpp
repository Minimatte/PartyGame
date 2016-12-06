// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyGameInstance.h"

int UPartyGameInstance::GetRequiredWins()
{
	return RequiredWins;
}

void UPartyGameInstance::SetRequiredWins(int wins)
{
	RequiredWins = wins;
}

void UPartyGameInstance::SetLevelList(TArray<FName> levelnames) {
	Levels = levelnames;
}

bool UPartyGameInstance::AddPlayer(int PlayerID) {
	APlayerController* controller = UGameplayStatics::GetPlayerController(GWorld->GetLevel(0), PlayerID);

	FPartyPlayer player;

	player.PlayerID = PlayerID;
	player.Score = 0;

	
	if (!PlayerList.Contains(PlayerList.Num()))
		PlayerList.Add(PlayerList.Num(), player);

	if (Players.Contains(player)) {
		Players.Remove(player);
		return false;
	} else {
		Players.Add(player);
		return true;
	}

	//UGameplayStatics::GetGameMode(GWorld->GetLevel(0))
}

TArray<FPartyPlayer> UPartyGameInstance::GetPlayers() {
	return Players;
}

FPartyPlayer UPartyGameInstance::GetPlayer(int PlayerControllerID) {

	FPartyPlayer ret;

	ret.PlayerID = PlayerControllerID;
	ret.Score = 0;

	for (int i = 0; i < Players.Num(); i++) {
		if (Players[i].PlayerID == PlayerControllerID) {
			ret = Players[i];
			break;
		}
	}

	return ret;
}

int UPartyGameInstance::IndexOfPlayer(int PlayerID) {

	int id = -1;

	for (int i = 0; i < Players.Num(); i++) {
		if (Players[i].PlayerID == PlayerID) {
			id = i;
			break;
		}
	}

	return id;
}

FPartyPlayer UPartyGameInstance::GetLeadingPlayer()
{

	FPartyPlayer leader = Players[0];

	for (int i = 0; i < Players.Num(); i++) {
		if (Players[i].Score > leader.Score) {
			leader = Players[i];
		}
	}
	
	return leader;
}
