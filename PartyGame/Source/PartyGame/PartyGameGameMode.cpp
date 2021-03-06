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
			if (ginstance->GetLeadingPlayer().Score == ginstance->RequiredWins)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "Win: " + FString::SanitizeFloat(ginstance->GetLeadingPlayer().PlayerID));
				ginstance->Levels.SetNum(0);
				return -1;
			}

			return newscore.Score;
		}
	}
	return -1;
}

void APartyGameGameMode::EmptyPlayerList()
{
	UPartyGameInstance *gi = Cast<UPartyGameInstance>(GetGameInstance());	
	gi->Levels.Empty();
	gi->PlayerList.Empty();
	gi->Players.Empty();
}

bool APartyGameGameMode::CheckLastManStanding()
{
	if (GameOver)
		return GameOver;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APartyPlayerCharacter::StaticClass(), FoundActors);

	if (FoundActors.Num() == 1) {
		// One player left
		GameOver = true;
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &APartyGameGameMode::NextMap, ScoreScreenTime / 10, false);

		int playerID = UGameplayStatics::GetPlayerControllerID(Cast<APlayerController>(FoundActors[0]->GetInstigatorController()));
		int newscore = GiveScore(playerID);

	}
	else if (FoundActors.Num() == 0) {
	
		GameOver = true;
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &APartyGameGameMode::NextMap, 0.3f, false);
	}

	return GameOver;

}

void APartyGameGameMode::PlayerWin(APlayerController* playerController) {
	if (GameOver)
		return;

	GameOver = true;
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &APartyGameGameMode::NextMap, ScoreScreenTime / 10, false);

	int playerID = UGameplayStatics::GetPlayerControllerID(Cast<APlayerController>(playerController));
	int newscore = GiveScore(playerID);

}

void APartyGameGameMode::NextMap()
{
	UPartyGameInstance *gi = Cast<UPartyGameInstance>(GetGameInstance());
	if (gi->Levels.Num() > 0) {
		gi->NextMap = gi->Levels[FMath::RandRange(0, gi->Levels.Num() - 1)];
		UGameplayStatics::OpenLevel(GetWorld(), gi->NextMap);
	}
	else {
		UGameplayStatics::OpenLevel(GetWorld(), "StartLevel");


	}
}

void APartyGameGameMode::CreatePlayer(APartyPlayerController* playercontroller)
{
	PlayerControllers.Add(playercontroller);
}

int APartyGameGameMode::GetAmountOfPlayers() {

	return 0;
}

int APartyGameGameMode::GetTempScore(AActor * actor)
{
	if (!GameModeScore.Contains(actor))
		GameModeScore.Add(actor, 0);
	int x(*GameModeScore.Find(actor));
	return x;
}

void APartyGameGameMode::AddTempScore(AActor * actor, int v)
{
	if (GameModeScore.Contains(actor)) {
		int x(*GameModeScore.Find(actor));
		GameModeScore.Emplace(actor, (x + v));
	}
	else {
		GameModeScore.Add(actor, v);
	}
}

void APartyGameGameMode::BeginPlay() {
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("BEGIN PLAY GAME MODE"));
	GameModeScore.Empty();

	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), TSubclassOf<APartyPlayerCharacter>(), foundActors);

	for (int i = 0; i < foundActors.Num(); i++) {
		GameModeScore.Add(foundActors[i], 0);
	}

}
