// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyPlayerController.h"
#include "PartyPlayerCharacter.h"


void APartyPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();

	InputComponent->BindAxis("Right", this, &APartyPlayerController::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &APartyPlayerController::PlayerJump);
}


void APartyPlayerController::MoveRight(float Value) {
	const APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());
	if (!ControlledCharacter->CanMove)
		return;

	if (ControlledCharacter != NULL && Value != 0.0f) {
		// find out which way is right
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction

		GetPawn()->AddMovementInput(Direction, Value);

		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Value"));
	}
}

// Called every frame
void APartyPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	
	
}

void APartyPlayerController::PlayerJump() {
	APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());
	

	if (ControlledCharacter != NULL) {
		GetCharacter()->Jump();
		if (!GetCharacter()->GetMovementComponent()->IsMovingOnGround() && ControlledCharacter->CanWallJump) {
			FHitResult resultRight;
			FHitResult resultLeft;
			FVector start = GetCharacter()->GetActorLocation();
			FVector end = start + GetCharacter()->GetActorRightVector() * 50;
			FVector leftEnd = start + GetCharacter()->GetActorRightVector() * 50 * -1;

			FCollisionQueryParams CollisionParams;
			CollisionParams.AddIgnoredActor(GetCharacter());

			GetWorld()->LineTraceSingleByChannel(resultRight, start, end, ECollisionChannel::ECC_Visibility, CollisionParams);
			GetWorld()->LineTraceSingleByChannel(resultLeft, start, leftEnd, ECollisionChannel::ECC_Visibility, CollisionParams);

			float direction = 0;

			if (resultRight.IsValidBlockingHit()) {
				direction = 1;
			} else if (resultLeft.IsValidBlockingHit()) {
				direction = -1;
			} 

			if (direction != 0) {
				FVector newVelocity = -GetCharacter()->GetActorRightVector() * 500 * direction + GetCharacter()->GetActorUpVector() * 500;
				GetCharacter()->LaunchCharacter(newVelocity, true, true);
				ControlledCharacter->CanMove = false;
			}

		} 
			
		
	}
}
