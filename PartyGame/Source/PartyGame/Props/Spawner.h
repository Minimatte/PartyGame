// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class PARTYGAME_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, Category = "Spawner")
		TSubclassOf<class AActor> SpawnObject;
	
	UPROPERTY(EditAnywhere, Category = "Spawner")
		float SpawnTime = 5;

	UPROPERTY(EditAnywhere, Category = "Spawner")
		bool SpawnAtStart = true;

	UPROPERTY(EditAnywhere, Category = "Spawner")
		bool SpawnOnlyOnce = false;


	UFUNCTION(BlueprintCallable, Category = "Spawner")
		void SpawnActor();
};
