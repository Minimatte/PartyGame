// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "CameraHandler.h"
#include "PartyPlayerCharacter.h"
TArray<APartyPlayerCharacter> players;

// Sets default values
ACameraHandler::ACameraHandler()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraHandler::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACameraHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACameraHandler::LerpTowardsAverage()
{
	FVector averagePosition = FVector(0, 0, 0);
	int count = 0;
	for (TActorIterator<APartyPlayerCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		count++;
		// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
		APartyPlayerCharacter *Mesh = *ActorItr;
		averagePosition += ActorItr->GetActorLocation();
	}

	averagePosition = averagePosition / count;

	averagePosition = FMath::Lerp(GetActorLocation(), averagePosition, GetWorld()->GetDeltaSeconds() * lerpSpeed);
	SetActorLocation(averagePosition);

	// Set the spring arm length
	
	USpringArmComponent* SAC = FindComponentByClass<USpringArmComponent>();
	if (SAC)
	{
		float targetLength = SpringArmBase  * SpringArmMultiplier;
		targetLength = FMath::Lerp(SAC->TargetArmLength, targetLength, GetWorld()->GetDeltaSeconds() * lerpSpeed);
		SAC->TargetArmLength = targetLength;
	}

	
}

