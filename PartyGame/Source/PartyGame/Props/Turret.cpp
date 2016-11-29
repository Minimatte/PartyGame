// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "Turret.h"


// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

	if (TurretActive) {
		EnableTurret();
	}
	
}

// Called every frame
void ATurret::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATurret::ShootTurret() {
	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = Instigator;
	GetWorld()->SpawnActor<AActor>(SpawnObject, GetActorLocation(), GetActorRotation(), SpawnParams);

}

void ATurret::ShootTurretFromLocation(FVector Location) {
	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = Instigator;
	GetWorld()->SpawnActor<AActor>(SpawnObject, Location, GetActorRotation(), SpawnParams);
}

void ATurret::DisableTurret() {
	GetWorldTimerManager().ClearTimer(TurretHandle);
	TurretActive = false;
}

void ATurret::EnableTurret() {
	float timer = Interval + FMath::RandRange(-IntervalOffset, IntervalOffset);

	GetWorldTimerManager().SetTimer(TurretHandle, this, &ATurret::ShootTurret, timer, true);
	TurretActive = true;
}

void ATurret::SetProjectile(TSubclassOf<class AActor> newActor)
{
	SpawnObject = newActor;
}
