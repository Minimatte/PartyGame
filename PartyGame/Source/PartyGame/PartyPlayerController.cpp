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
	InputComponent->BindAction("Push", IE_Pressed, this, &APartyPlayerController::Push);
}

void APartyPlayerController::MoveUp(float Value) {
	const APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());


	if (ControlledCharacter != NULL && Value != 0.0f) {

		if (!ControlledCharacter->CanMoveXAxis)
			return;

		if (!ControlledCharacter->CanMove)
			return;

		if (!ControlledCharacter->MovementEnabled)
			return;

		// find out which way is right
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		// add movement in that direction
		GetCharacter()->AddMovementInput(Direction, Value);


	}
}

void APartyPlayerController::MoveRight(float Value) {
	const APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());
	if (ControlledCharacter != NULL && Value != 0.0f) {
		if (!ControlledCharacter->MovementEnabled)
			return;
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
		if (!ControlledCharacter->CanPawnJump)
			return;

		if (!ControlledCharacter->MovementEnabled)
			return;

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

			}
			else if (resultLeft.IsValidBlockingHit()) {
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

void APartyPlayerController::EnableCharacterMovement() {
	APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());
	if (::IsValid(ControlledCharacter))
		ControlledCharacter->CanMove = true;
}

void APartyPlayerController::Push()
{
	APartyPlayerCharacter* ControlledCharacter = Cast<APartyPlayerCharacter>(GetPawn());


	if (::IsValid(ControlledCharacter) && ControlledCharacter->CanMove) {

		TArray<FHitResult> hits;
		FVector start = ControlledCharacter->GetActorLocation();
		FVector end = start + FVector(0, 0, 1);

		FCollisionQueryParams TraceParams(FName(TEXT("Trace")), true, ControlledCharacter);

		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = false;

		TraceParams.AddIgnoredActor(ControlledCharacter);

		GetWorld()->SweepMultiByChannel(hits, start, end, FQuat(), ECollisionChannel::ECC_WorldDynamic, FCollisionShape::MakeSphere(150), TraceParams);
		for (int i = 0; i < hits.Num(); i++) {


			APartyPlayerCharacter* hit = Cast<APartyPlayerCharacter>(hits[i].GetActor());
			if (::IsValid(hit)) {

				FVector Direction = (hit->GetActorLocation() - ControlledCharacter->GetActorLocation());
				Direction.Normalize();

				Direction *= 1000;

				hit->LaunchCharacter(Direction, true, true);
				DisableCharacterMovement();

				FTimerHandle handler;
				GetWorldTimerManager().SetTimer(handler, this, &APartyPlayerController::EnableCharacterMovement, 0.2, false);
			}
		}
	}
}
