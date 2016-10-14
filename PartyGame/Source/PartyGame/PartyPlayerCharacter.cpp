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

	CurrentHealth = MaxHealth;

	AutoPossessPlayer = EAutoReceiveInput::Player1;
	AutoPossessPlayer = EAutoReceiveInput::Player2;
	AutoPossessPlayer = EAutoReceiveInput::Player3;
	AutoPossessPlayer = EAutoReceiveInput::Player4;

}

// Called every frame
void APartyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CanMove && GetMovementComponent()->IsMovingOnGround()) {
		CanMove = true;
		
	}

}

void APartyPlayerCharacter::TakeDamage(float damage) {
	CurrentHealth -= damage;

	if (CurrentHealth <= 0) {
		GetController()->UnPossess();
		Kill();
	}
}

void APartyPlayerCharacter::Heal(float health) {
	CurrentHealth += health;

	if (CurrentHealth > MaxHealth) {
		CurrentHealth = MaxHealth;
	}
}

void APartyPlayerCharacter::Kill() {
	Destroy();
}

float APartyPlayerCharacter::GetCurrentHealth() {
	return CurrentHealth;
}

float APartyPlayerCharacter::GetMaxHealth() {
	return MaxHealth;
}
