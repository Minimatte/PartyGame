// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyPlayerController.h"
#include "PartyPlayerCharacter.h"


void APartyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	InputComponent->BindAxis("Right", this, &APartyPlayerController::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &APartyPlayerController::PlayerJump);
}


void APartyPlayerController::MoveRight(float Value) {
	const APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());
	if (ControlledCharacter != NULL && Value != 0.0f) {
		// find out which way is right
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction

		if (Value > 0) {
			Value = 1;
		}
		else {
			Value = -1;
		}
		GetPawn()->AddMovementInput(Direction, Value);

		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Value"));
	}
}

void APartyPlayerController::PlayerJump()
{
	const APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());
	if (ControlledCharacter != NULL) {
		GetCharacter()->Jump();
	}
}
