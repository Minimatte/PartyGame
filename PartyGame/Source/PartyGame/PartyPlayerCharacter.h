// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PartyPlayerCharacter.generated.h"

UCLASS()
class PARTYGAME_API APartyPlayerCharacter : public ACharacter {
	GENERATED_BODY()

	
public:

	UPROPERTY(EditAnywhere)
		UMaterialInterface* PlayerMaterial;


	UPROPERTY(EditAnywhere)
		bool CanMoveXAxis = false;

	
	// Sets default values for this character's properties
	APartyPlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Party Player")
		void TakeDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "Party Player")
		void Heal(float health);

	UFUNCTION(BlueprintCallable, Category = "Party Player")
		void Kill();

	UPROPERTY(EditAnywhere)
		bool CanPawnJump = true;
	
	UPROPERTY(EditAnywhere)
		bool CanWallJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanMove;

	UPROPERTY(EditAnywhere)
		float MaxHealth;

	UPROPERTY(EditAnywhere)
		float CurrentHealth;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Player")
		virtual float GetCurrentHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Player")
		virtual float GetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Party Player")
		void DisableMovement();

	UFUNCTION(BlueprintCallable, Category = "Party Player")
		void EnableMovement();

	//If the movement component is enabled
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool MovementEnabled = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanPush = false;
};
