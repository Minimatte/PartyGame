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

}

// Called every frame
void APartyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void APartyPlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	

}

