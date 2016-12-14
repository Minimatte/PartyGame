// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyGameLib.h"
#include "PartyPlayerCharacter.h"
#include "PartyPlayerController.h"
#include "PartyGameInstance.h"
// Sets default values
APartyPlayerCharacter::APartyPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APartyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	AutoPossessPlayer = EAutoReceiveInput::Player1;
	AutoPossessPlayer = EAutoReceiveInput::Player2;
	AutoPossessPlayer = EAutoReceiveInput::Player3;
	AutoPossessPlayer = EAutoReceiveInput::Player4;
	int id = UGameplayStatics::GetPlayerControllerID(Cast<APlayerController>(GetInstigatorController()));
	UPartyGameInstance *gi = Cast<UPartyGameInstance>(GetGameInstance());


	if (::IsValid(GetComponentsByTag(UStaticMeshComponent::StaticClass(), "Mesh")[0])) {

		FLinearColor color = UPartyGameLib::GetPlayerColor(gi->GetPlayer(id).PlayerID);
		UStaticMeshComponent *c = Cast<UStaticMeshComponent>(GetComponentsByTag(UStaticMeshComponent::StaticClass(), "Mesh")[0]);


		UMaterialInstanceDynamic *DynamicMaterial = UMaterialInstanceDynamic::Create(PlayerMaterial, this);

		DynamicMaterial->SetVectorParameterValue("Color", color);

		c->SetMaterial(0, DynamicMaterial);
		int i = gi->GetPlayer(id).PlayerID;
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, color.ToString() + " - " + FString::SanitizeFloat(i));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "There is no tag Mesh on the player, cant set player color.");

	}


}

// Called every frame
void APartyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CanMove && GetMovementComponent()->IsMovingOnGround() && MovementEnabled) {
		CanMove = true;

	}

}

void APartyPlayerCharacter::TakeDamage(float damage) {
	CurrentHealth -= damage;


	if (CurrentHealth <= 0) {
		GetController()->UnPossess();
		Kill();
	}

	if (CurrentHealth > MaxHealth)
		CurrentHealth = MaxHealth;
}

void APartyPlayerCharacter::Heal(float health) {
	CurrentHealth += health;

	if (CurrentHealth > MaxHealth) {
		CurrentHealth = MaxHealth;
	}
}

void APartyPlayerCharacter::Kill() {
	Destroy();
}

float APartyPlayerCharacter::GetCurrentHealth() {
	return CurrentHealth;
}

float APartyPlayerCharacter::GetMaxHealth() {
	return MaxHealth;
}

void APartyPlayerCharacter::DisableMovement() {
	MovementEnabled = false;
}

void APartyPlayerCharacter::EnableMovement() {
	MovementEnabled = true;
}