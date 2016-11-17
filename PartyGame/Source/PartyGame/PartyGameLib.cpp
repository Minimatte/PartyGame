// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyGameGameMode.h"
#include "PartyGameLib.h"

FColor UPartyGameLib::GetPlayerColor(int id) {

	switch (id) {
	case 0:
		return FColor::Red;
	case 1:
		return FColor::Blue;
	case 2:
		return FColor::Green;
	case 3:
		return FColor::Yellow; 
	case 4:
		return FColor::Purple;
	case 5:
		return FColor::White;
	}

	return FColor::Black;
	
}

AActor* UPartyGameLib::GetPlayerFurthestTo(EDirectionEnum direction) {
	
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GWorld->GetLevel(0), APartyPlayerCharacter::StaticClass(), FoundActors);
	AActor* ActorToReturn = FoundActors[0]; 

	switch (direction) {
	case EDirectionEnum::VE_Right:

		for (int i = 0; i < FoundActors.Num(); i++) {
			if (ActorToReturn->GetActorLocation().Y < FoundActors[i]->GetActorLocation().Y)
				ActorToReturn = FoundActors[i];
		}

		break;
	case EDirectionEnum::VE_Left:

		for (int i = 0; i < FoundActors.Num(); i++) {
			if (FoundActors[i]->GetActorLocation().Y < ActorToReturn->GetActorLocation().Y)
				ActorToReturn = FoundActors[i];
		}

		break;
	case EDirectionEnum::VE_Up:

		for (int i = 0; i < FoundActors.Num(); i++) {
			if (ActorToReturn->GetActorLocation().Z < FoundActors[i]->GetActorLocation().Z)
				ActorToReturn = FoundActors[i];
		}

		break;
	case EDirectionEnum::VE_Down:

		for (int i = 0; i < FoundActors.Num(); i++) {
			if (FoundActors[i]->GetActorLocation().Z < ActorToReturn->GetActorLocation().Z)
				ActorToReturn = FoundActors[i];
		}

		break;
	default:
		break;
	}



	return ActorToReturn;
}

bool UPartyGameLib::IsOnScreen(AActor* Actor, float TimeThreashold) {
	//Empty any previous entries

	float delta = Actor->GetWorld()->TimeSeconds - Actor->GetLastRenderTime();
	if (delta < TimeThreashold)
		return true;
	
	else return false;

}

void UPartyGameLib::AddScore(int PlayerId)
{
}

