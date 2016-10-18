// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "PartyPlayerController.generated.h"

/**
 *
 */
UCLASS()
class PARTYGAME_API APartyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:


	bool Boosting = false;
	FVector BoostingLocation;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void SetupInputComponent();

	UFUNCTION()
		void MoveRight(float Value);

	UFUNCTION()
		void PlayerJump();

	UFUNCTION()
		void Boost();
};
