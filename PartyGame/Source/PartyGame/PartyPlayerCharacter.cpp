// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyPlayerCharacter.h"
#include <sstream>
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
void APartyPlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	
}

// Called to bind functionality to input
void APartyPlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("Right", this, &APartyPlayerCharacter::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &APartyPlayerCharacter::Jump);

}



void APartyPlayerCharacter::MoveRight(float Value) {
	if ((Controller != NULL) && (Value != 0.0f)) {
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction

		if (Value > 0) {
			Value = 1;
		} else {
			Value = -1;
		}

		AddMovementInput(Direction, Value);
		
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Value"));
	}
}

