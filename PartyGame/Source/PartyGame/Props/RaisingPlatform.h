// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RaisingPlatform.generated.h"

UCLASS()
class PARTYGAME_API ARaisingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARaisingPlatform();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Offset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PlatformSpeed = 5;

	UFUNCTION(BlueprintCallable, Category = "Raising Platform")
		void Raise();
	
	UFUNCTION(BlueprintCallable, Category = "Raising Platform")
		void Lower();
private:
	FVector StartLocation;
	FVector TargetLocation;
};
