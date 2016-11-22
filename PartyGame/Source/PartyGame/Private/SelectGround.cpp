// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "SelectGround.h"


// Sets default values
ASelectGround::ASelectGround()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASelectGround::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASelectGround::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASelectGround::SetValue(int v)
{
	value = v;
}

int ASelectGround::GetValue()
{
	return value;
}

