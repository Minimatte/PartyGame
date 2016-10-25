// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyPlayerCharacter.h"
#include "PartyGameGameMode.h"
#include "PartyGameInstance.h"

TArray<AActor*> APartyGameGameMode::GetAllSpawnLocations()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), FoundActors);


	return FoundActors;
}

int APartyGameGameMode::GiveScore(int PlayerId)
{

	UPartyGameInstance* ginstance = Cast<UPartyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	

	for (int i = 0; i < ginstance->Players.Num(); i++) {

		if (ginstance->Players[i].PlayerID == PlayerId) {

			FPartyPlayer newscore = FPartyPlayer(ginstance->Players[i].PlayerID, ginstance->Players[i].Score + 1);

			ginstance->Players[i] = newscore;
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "Added score");
			return newscore.Score;
		}
	}
	return -1;
}

void APartyGameGameMode::CheckLastManStanding()
{
	if (GameOver)
		return;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APartyPlayerCharacter::StaticClass(), FoundActors);

	if (FoundActors.Num() == 1) {
		// One player left
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "ONE PLAYER LEFT");
		//int winnerID = FoundActors[0]->GetInstigatorController()->GetUniqueID;
		GameOver = true;
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &APartyGameGameMode::NextMap, 0.3f, false);
		
		int playerID = UGameplayStatics::GetPlayerControllerID(Cast<APlayerController>(FoundActors[0]->GetInstigatorController()));
		int newscore = GiveScore(playerID);
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, FString::SanitizeFloat(newscore));
	}
	else if (FoundActors.Num() == 0) {
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "DRAW");
		GameOver = true;
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &APartyGameGameMode::NextMap, 0.3f, false);
	}

}

void APartyGameGameMode::NextMap()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Level_FallingBalls");
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
