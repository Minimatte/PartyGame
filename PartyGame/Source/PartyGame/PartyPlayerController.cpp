// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyPlayerController.h"
#include "PartyPlayerCharacter.h"


void APartyPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();
	
	InputComponent->BindAxis("Up", this, &APartyPlayerController::MoveUp);
	

	InputComponent->BindAxis("Right", this, &APartyPlayerController::MoveRight);
	InputComponent->BindAxis("RightStickX");
	InputComponent->BindAxis("RightStickY");
	InputComponent->BindAction("Jump", IE_Pressed, this, &APartyPlayerController::PlayerJump);
	InputComponent->BindAction("Debug", IE_Pressed, this, &APartyPlayerController::Boost);
}

void APartyPlayerController::MoveUp(float Value) {
	const APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());


	if (ControlledCharacter != NULL && Value != 0.0f) {

	if (!ControlledCharacter->CanMoveXAxis)
		return;
		if (!ControlledCharacter->CanMove)
			return;
		// find out which way is right
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		// add movement in that direction

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White,Direction.ToString());
		GetPawn()->AddMovementInput(Direction, Value);

	}
}

void APartyPlayerController::MoveRight(float Value) {
	const APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());
	if (ControlledCharacter != NULL && Value != 0.0f) {

		if (!ControlledCharacter->CanMove)
			return;
		// find out which way is right
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction

		GetPawn()->AddMovementInput(Direction, Value);

	}
}

void APartyPlayerController::Boost() {
	float power = 600;
	float xMult = InputComponent->GetAxisValue("RightStickX");
	float yMult = InputComponent->GetAxisValue("RightStickY");

	FVector dir = FVector(0, xMult, yMult);

	GetCharacter()->LaunchCharacter(dir * power, false, false);

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
			float wallJumpDirection = -2;
			float axisDirection = InputComponent->GetAxisValue("Right");

			if (resultRight.IsValidBlockingHit()) {
				direction = 1;
				wallJumpDirection = -1;

			} else if (resultLeft.IsValidBlockingHit()) {
				direction = -1;
				wallJumpDirection = 1;
			}

			if (direction != 0) {
				FVector newVelocity = -GetCharacter()->GetActorRightVector() * 500 * direction + GetCharacter()->GetActorUpVector() * 500;
				GetCharacter()->LaunchCharacter(newVelocity, true, true);
				ControlledCharacter->CanMove = false;
			}

		}
	}
}

void APartyPlayerController::DisableCharacterMovement() {
	APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());
	ControlledCharacter->CanMove = false;
}