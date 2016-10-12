// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyGameGameMode.h"

void APartyGameGameMode::CreatePlayer(APartyPlayerController* playercontroller)
{
	PlayerControllers.Add(playercontroller);
}

int APartyGameGameMode::GetAmountOfPlayers() {

	return 0;
}

void APartyGameGameMode::BeginPlay() {
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("BEGIN PLAY GAME MODE"));
}