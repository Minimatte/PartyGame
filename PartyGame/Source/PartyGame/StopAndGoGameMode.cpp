// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "StopAndGoGameMode.h"

FColor AStopAndGoGameMode::NextMode() {
	switch (mode) {
	case EStopAndGo::VE_Go:
		mode = EStopAndGo::VE_Warning;
		return FColor::Yellow;
	case EStopAndGo::VE_Stop:
		mode = EStopAndGo::VE_Go;
		return FColor::Green;
	case EStopAndGo::VE_Warning:
		mode = EStopAndGo::VE_Stop;
		return FColor::Red;
	}

	return FColor::Black;

}

EStopAndGo AStopAndGoGameMode::GetMode() {
	return mode;
}
