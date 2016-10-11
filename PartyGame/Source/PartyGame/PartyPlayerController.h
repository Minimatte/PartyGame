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


	void SetupInputComponent();

	UFUNCTION()
		void MoveRight(float Value);

	UFUNCTION()
		void PlayerJump();
};
