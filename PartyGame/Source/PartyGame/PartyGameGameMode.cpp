// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyPlayerCharacter.h"
#include "PartyGameGameMode.h"

void APartyGameGameMode::CheckLastManStanding()
{
	if (GameOver)
		return;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APartyPlayerCharacter::StaticClass(), FoundActors);

	if (FoundActors.Num() == 1) {
		// One player left
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "ONE PLAYER LEFT");
//		int winnerID = FoundActors[0]->GetInstigatorController()->GetUniqueID;
		GameOver = true;
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(
			UnusedHandle, this, &APartyGameGameMode::NextMap, 0.3f, false);
	}
	else if (FoundActors.Num() == 0) {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "DRAW");
		GameOver = true;
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(
			UnusedHandle, this, &APartyGameGameMode::NextMap, 0.3f, false);
	}

}

void APartyGameGameMode::NextMap()
{
	UGameplayStatics::OpenLevel(GetWorld(), "StartLevel");
}

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