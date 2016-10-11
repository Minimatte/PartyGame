// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "PartyGame.h"
#include "PartyGame.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1PartyGame() {}
	void APartyGameGameMode::StaticRegisterNativesAPartyGameGameMode()
	{
	}
	IMPLEMENT_CLASS(APartyGameGameMode, 3326978834);
	void APartyPlayerCharacter::StaticRegisterNativesAPartyPlayerCharacter()
	{
		FNativeFunctionRegistrar::RegisterFunction(APartyPlayerCharacter::StaticClass(), "MoveRight",(Native)&APartyPlayerCharacter::execMoveRight);
	}
	IMPLEMENT_CLASS(APartyPlayerCharacter, 1415357045);
	void APartyPlayerController::StaticRegisterNativesAPartyPlayerController()
	{
	}
	IMPLEMENT_CLASS(APartyPlayerController, 455809018);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();
	ENGINE_API class UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API class UClass* Z_Construct_UClass_APlayerController();

	PARTYGAME_API class UClass* Z_Construct_UClass_APartyGameGameMode_NoRegister();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyGameGameMode();
	PARTYGAME_API class UFunction* Z_Construct_UFunction_APartyPlayerCharacter_MoveRight();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyPlayerCharacter_NoRegister();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyPlayerCharacter();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyPlayerController_NoRegister();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyPlayerController();
	PARTYGAME_API class UPackage* Z_Construct_UPackage__Script_PartyGame();
	UClass* Z_Construct_UClass_APartyGameGameMode_NoRegister()
	{
		return APartyGameGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_APartyGameGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameMode();
			Z_Construct_UPackage__Script_PartyGame();
			OuterClass = APartyGameGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x2090028C;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PartyGameGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("PartyGameGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APartyGameGameMode(Z_Construct_UClass_APartyGameGameMode, &APartyGameGameMode::StaticClass, TEXT("APartyGameGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APartyGameGameMode);
	UFunction* Z_Construct_UFunction_APartyPlayerCharacter_MoveRight()
	{
		struct PartyPlayerCharacter_eventMoveRight_Parms
		{
			float Value;
		};
		UObject* Outer=Z_Construct_UClass_APartyPlayerCharacter();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("MoveRight"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00020401, 65535, sizeof(PartyPlayerCharacter_eventMoveRight_Parms));
			UProperty* NewProp_Value = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Value"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Value, PartyPlayerCharacter_eventMoveRight_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("PartyPlayerCharacter.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APartyPlayerCharacter_NoRegister()
	{
		return APartyPlayerCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_APartyPlayerCharacter()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage__Script_PartyGame();
			OuterClass = APartyPlayerCharacter::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_APartyPlayerCharacter_MoveRight());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_APartyPlayerCharacter_MoveRight(), "MoveRight"); // 1679761400
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PartyPlayerCharacter.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("PartyPlayerCharacter.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APartyPlayerCharacter(Z_Construct_UClass_APartyPlayerCharacter, &APartyPlayerCharacter::StaticClass, TEXT("APartyPlayerCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APartyPlayerCharacter);
	UClass* Z_Construct_UClass_APartyPlayerController_NoRegister()
	{
		return APartyPlayerController::StaticClass();
	}
	UClass* Z_Construct_UClass_APartyPlayerController()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APlayerController();
			Z_Construct_UPackage__Script_PartyGame();
			OuterClass = APartyPlayerController::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900284;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PartyPlayerController.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("PartyPlayerController.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APartyPlayerController(Z_Construct_UClass_APartyPlayerController, &APartyPlayerController::StaticClass, TEXT("APartyPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APartyPlayerController);
	UPackage* Z_Construct_UPackage__Script_PartyGame()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/PartyGame")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0xBD6253F7;
			Guid.B = 0xB42935E4;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
