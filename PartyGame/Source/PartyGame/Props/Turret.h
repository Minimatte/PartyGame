// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Turret.generated.h"

UCLASS()
class PARTYGAME_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, Category = "Turret")
		TSubclassOf<class AActor> SpawnObject;

	UPROPERTY(EditAnywhere, Category = "Turret")
		float Interval = 5;

	UPROPERTY(EditAnywhere, Category = "Turret")
		float IntervalOffset = 0;

	UPROPERTY(EditAnywhere, Category = "Turret")
		bool TurretActive = true;

	UFUNCTION(BlueprintCallable, Category = "Turret")
		void ShootTurret();

	UFUNCTION(BlueprintCallable, Category = "Turret")
		void ShootTurretFromLocation(FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Turret")
		void DisableTurret();

	UFUNCTION(BlueprintCallable, Category = "Turret")
		void EnableTurret();
private:
	FTimerHandle TurretHandle;
};
