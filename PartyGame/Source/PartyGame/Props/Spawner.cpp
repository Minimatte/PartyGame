// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "Spawner.h"


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	if (SpawnAtStart) {
		SpawnActor();
	}
}

// Called every frame
void ASpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASpawner::SpawnActor() {

	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = Instigator;
	AActor* DroppedItem = GetWorld()->SpawnActor<AActor>(SpawnObject, GetActorLocation(), GetActorRotation(), SpawnParams);
	
	
}

