// Fill out your copyright notice in the Description page of Project Settings.

#include "PartyGame.h"
#include "PartyGameGameMode.h"
#include "PartyGameLib.h"

FColor UPartyGameLib::GetPlayerColor(int id) {

	switch (id) {
	case 0:
		return FColor::Red;
		break;
	case 1:
		return FColor::Blue;
		break;
	case 2:
		return FColor::Green;
		break;
	case 3:
		return FColor::Yellow; 
		break;
	case 4:
		return FColor::Purple;
		break;
	case 5:
		return FColor::White;
	default:
		return FColor::Magenta;
		break;
	}

	return FColor::Black;
	
}


