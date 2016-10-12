// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CameraHandler.generated.h"

UCLASS()
class PARTYGAME_API ACameraHandler : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACameraHandler();

	UPROPERTY(EditAnywhere)
		float lerpSpeed = 10;
	UPROPERTY(EditAnywhere)
		float SpringArmBase = 300;
	UPROPERTY(EditAnywhere)
		float SpringArmMultiplier = 2;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "CameraHandler")
		void LerpTowardsAverage();

};
