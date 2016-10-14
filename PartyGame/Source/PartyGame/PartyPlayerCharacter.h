// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PartyPlayerCharacter.generated.h"

UCLASS()
class PARTYGAME_API APartyPlayerCharacter : public ACharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APartyPlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Party Player")
		virtual void TakeDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "Party Player")
		virtual void Heal(float health);

	UFUNCTION(BlueprintCallable, Category = "Party Player")
		virtual void Kill();

	UPROPERTY(EditAnywhere)
		bool CanWallJump;

	UPROPERTY(EditAnywhere)
		bool CanMove;

	UPROPERTY(EditAnywhere)
		float MaxHealth;

	UPROPERTY(EditAnywhere)
		float CurrentHealth;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Player")
		virtual float GetCurrentHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Party Player")
		virtual float GetMaxHealth();
};
