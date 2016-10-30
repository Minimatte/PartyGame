// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "RaisingPlatform.h"


// Sets default values
ARaisingPlatform::ARaisingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARaisingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	TargetLocation = StartLocation;
}

// Called every frame
void ARaisingPlatform::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector currentLocation = FMath::VInterpConstantTo(GetActorLocation(), TargetLocation, DeltaTime, PlatformSpeed);
	SetActorLocation(currentLocation);
}

void ARaisingPlatform::Raise()
{
	TargetLocation = StartLocation;
}

void ARaisingPlatform::Lower()
{
	TargetLocation = StartLocation + Offset;
}

