// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "Spawner.h"


// Sets default values
ASpawner::ASpawner() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay() {
	Super::BeginPlay();

	if (SpawnAtStart) {
		SpawnActor();
	}
}

// Called every frame
void ASpawner::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	float time = GetWorld()->TimeSeconds;
	if ((int)FMath::Fmod(time, SpawnTime) == 0 && !HasSpawned) {
		HasSpawned = true;
		SpawnActor();
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ASpawner::ResetSpawnOnce, SpawnTime - (SpawnTime / 10), false);
	}

}

void ASpawner::SpawnActor() {
	
	if (::IsValid(DroppedItem))
		return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = Instigator;
	DroppedItem = GetWorld()->SpawnActor<AActor>(SpawnObject, GetActorLocation(), GetActorRotation(), SpawnParams);


}

void ASpawner::ResetSpawnOnce() {
	HasSpawned = false;
}

