// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SelectGround.generated.h"

UCLASS()
class PARTYGAME_API ASelectGround : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASelectGround();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
		int value;

	UFUNCTION(BlueprintCallable, Category = "Select Game Mode")
		void SetValue(int v);
	
	UFUNCTION(BlueprintCallable, Category = "Select Game Mode")
		int GetValue();
};
