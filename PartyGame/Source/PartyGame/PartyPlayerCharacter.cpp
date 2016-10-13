// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyPlayerCharacter.h"
#include "PartyPlayerController.h"
// Sets default values
APartyPlayerCharacter::APartyPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APartyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	AutoPossessPlayer = EAutoReceiveInput::Player1;
	AutoPossessPlayer = EAutoReceiveInput::Player2;
	AutoPossessPlayer = EAutoReceiveInput::Player3;
	AutoPossessPlayer = EAutoReceiveInput::Player4;
	AutoPossessPlayer = EAutoReceiveInput::Player5;
	AutoPossessPlayer = EAutoReceiveInput::Player6;
}

// Called every frame
void APartyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CanMove && GetMovementComponent()->IsMovingOnGround()) {
		CanMove = true;
		
	}

}

// Called to bind functionality to input
void APartyPlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	
	

}

