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
	void ACameraHandler::StaticRegisterNativesACameraHandler()
	{
		FNativeFunctionRegistrar::RegisterFunction(ACameraHandler::StaticClass(), "LerpTowardsAverage",(Native)&ACameraHandler::execLerpTowardsAverage);
	}
	IMPLEMENT_CLASS(ACameraHandler, 2063050659);
	void APartyPlayerController::StaticRegisterNativesAPartyPlayerController()
	{
		FNativeFunctionRegistrar::RegisterFunction(APartyPlayerController::StaticClass(), "MoveRight",(Native)&APartyPlayerController::execMoveRight);
		FNativeFunctionRegistrar::RegisterFunction(APartyPlayerController::StaticClass(), "PlayerJump",(Native)&APartyPlayerController::execPlayerJump);
	}
	IMPLEMENT_CLASS(APartyPlayerController, 2593996755);
	void APartyGameGameMode::StaticRegisterNativesAPartyGameGameMode()
	{
		FNativeFunctionRegistrar::RegisterFunction(APartyGameGameMode::StaticClass(), "CreatePlayer",(Native)&APartyGameGameMode::execCreatePlayer);
		FNativeFunctionRegistrar::RegisterFunction(APartyGameGameMode::StaticClass(), "GetAmountOfPlayers",(Native)&APartyGameGameMode::execGetAmountOfPlayers);
	}
	IMPLEMENT_CLASS(APartyGameGameMode, 3311818518);
	void UPartyGameLib::StaticRegisterNativesUPartyGameLib()
	{
		FNativeFunctionRegistrar::RegisterFunction(UPartyGameLib::StaticClass(), "GetRandomColor",(Native)&UPartyGameLib::execGetRandomColor);
	}
	IMPLEMENT_CLASS(UPartyGameLib, 4048102525);
	void APartyPlayerCharacter::StaticRegisterNativesAPartyPlayerCharacter()
	{
	}
	IMPLEMENT_CLASS(APartyPlayerCharacter, 2749416004);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_APlayerController();
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FColor();
	ENGINE_API class UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API class UClass* Z_Construct_UClass_ACharacter();

	PARTYGAME_API class UFunction* Z_Construct_UFunction_ACameraHandler_LerpTowardsAverage();
	PARTYGAME_API class UClass* Z_Construct_UClass_ACameraHandler_NoRegister();
	PARTYGAME_API class UClass* Z_Construct_UClass_ACameraHandler();
	PARTYGAME_API class UFunction* Z_Construct_UFunction_APartyPlayerController_MoveRight();
	PARTYGAME_API class UFunction* Z_Construct_UFunction_APartyPlayerController_PlayerJump();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyPlayerController_NoRegister();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyPlayerController();
	PARTYGAME_API class UFunction* Z_Construct_UFunction_APartyGameGameMode_CreatePlayer();
	PARTYGAME_API class UFunction* Z_Construct_UFunction_APartyGameGameMode_GetAmountOfPlayers();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyGameGameMode_NoRegister();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyGameGameMode();
	PARTYGAME_API class UFunction* Z_Construct_UFunction_UPartyGameLib_GetRandomColor();
	PARTYGAME_API class UClass* Z_Construct_UClass_UPartyGameLib_NoRegister();
	PARTYGAME_API class UClass* Z_Construct_UClass_UPartyGameLib();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyPlayerCharacter_NoRegister();
	PARTYGAME_API class UClass* Z_Construct_UClass_APartyPlayerCharacter();
	PARTYGAME_API class UPackage* Z_Construct_UPackage__Script_PartyGame();
	UFunction* Z_Construct_UFunction_ACameraHandler_LerpTowardsAverage()
	{
		UObject* Outer=Z_Construct_UClass_ACameraHandler();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("LerpTowardsAverage"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("CameraHandler"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("CameraHandler.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ACameraHandler_NoRegister()
	{
		return ACameraHandler::StaticClass();
	}
	UClass* Z_Construct_UClass_ACameraHandler()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_PartyGame();
			OuterClass = ACameraHandler::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_ACameraHandler_LerpTowardsAverage());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_SpringArmMultiplier = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SpringArmMultiplier"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(SpringArmMultiplier, ACameraHandler), 0x0010000000000001);
				UProperty* NewProp_SpringArmBase = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SpringArmBase"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(SpringArmBase, ACameraHandler), 0x0010000000000001);
				UProperty* NewProp_lerpSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("lerpSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(lerpSpeed, ACameraHandler), 0x0010000000000001);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ACameraHandler_LerpTowardsAverage(), "LerpTowardsAverage"); // 3312060448
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("CameraHandler.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("CameraHandler.h"));
				MetaData->SetValue(NewProp_SpringArmMultiplier, TEXT("Category"), TEXT("CameraHandler"));
				MetaData->SetValue(NewProp_SpringArmMultiplier, TEXT("ModuleRelativePath"), TEXT("CameraHandler.h"));
				MetaData->SetValue(NewProp_SpringArmBase, TEXT("Category"), TEXT("CameraHandler"));
				MetaData->SetValue(NewProp_SpringArmBase, TEXT("ModuleRelativePath"), TEXT("CameraHandler.h"));
				MetaData->SetValue(NewProp_lerpSpeed, TEXT("Category"), TEXT("CameraHandler"));
				MetaData->SetValue(NewProp_lerpSpeed, TEXT("ModuleRelativePath"), TEXT("CameraHandler.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACameraHandler(Z_Construct_UClass_ACameraHandler, &ACameraHandler::StaticClass, TEXT("ACameraHandler"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACameraHandler);
	UFunction* Z_Construct_UFunction_APartyPlayerController_MoveRight()
	{
		struct PartyPlayerController_eventMoveRight_Parms
		{
			float Value;
		};
		UObject* Outer=Z_Construct_UClass_APartyPlayerController();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("MoveRight"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00020401, 65535, sizeof(PartyPlayerController_eventMoveRight_Parms));
			UProperty* NewProp_Value = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Value"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Value, PartyPlayerController_eventMoveRight_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("PartyPlayerController.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_APartyPlayerController_PlayerJump()
	{
		UObject* Outer=Z_Construct_UClass_APartyPlayerController();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("PlayerJump"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("PartyPlayerController.h"));
#endif
		}
		return ReturnFunction;
	}
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

				OuterClass->LinkChild(Z_Construct_UFunction_APartyPlayerController_MoveRight());
				OuterClass->LinkChild(Z_Construct_UFunction_APartyPlayerController_PlayerJump());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_APartyPlayerController_MoveRight(), "MoveRight"); // 3085419615
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_APartyPlayerController_PlayerJump(), "PlayerJump"); // 2457041703
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
	UFunction* Z_Construct_UFunction_APartyGameGameMode_CreatePlayer()
	{
		struct PartyGameGameMode_eventCreatePlayer_Parms
		{
			APartyPlayerController* playercontroller;
		};
		UObject* Outer=Z_Construct_UClass_APartyGameGameMode();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CreatePlayer"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(PartyGameGameMode_eventCreatePlayer_Parms));
			UProperty* NewProp_playercontroller = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("playercontroller"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(playercontroller, PartyGameGameMode_eventCreatePlayer_Parms), 0x0010000000000080, Z_Construct_UClass_APartyPlayerController_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Gamecontroller"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("PartyGameGameMode.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Create a new controller, add it to the list of players."));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_APartyGameGameMode_GetAmountOfPlayers()
	{
		struct PartyGameGameMode_eventGetAmountOfPlayers_Parms
		{
			int32 ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_APartyGameGameMode();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetAmountOfPlayers"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14020401, 65535, sizeof(PartyGameGameMode_eventGetAmountOfPlayers_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(ReturnValue, PartyGameGameMode_eventGetAmountOfPlayers_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("GameMode"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("PartyGameGameMode.h"));
#endif
		}
		return ReturnFunction;
	}
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

				OuterClass->LinkChild(Z_Construct_UFunction_APartyGameGameMode_CreatePlayer());
				OuterClass->LinkChild(Z_Construct_UFunction_APartyGameGameMode_GetAmountOfPlayers());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_PlayerControllers = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("PlayerControllers"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(PlayerControllers, APartyGameGameMode), 0x0010000000000001);
				UProperty* NewProp_PlayerControllers_Inner = new(EC_InternalUseOnlyConstructor, NewProp_PlayerControllers, TEXT("PlayerControllers"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_APartyPlayerController_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_APartyGameGameMode_CreatePlayer(), "CreatePlayer"); // 3412212296
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_APartyGameGameMode_GetAmountOfPlayers(), "GetAmountOfPlayers"); // 3377975198
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PartyGameGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("PartyGameGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
				MetaData->SetValue(NewProp_PlayerControllers, TEXT("Category"), TEXT("PartyGameGameMode"));
				MetaData->SetValue(NewProp_PlayerControllers, TEXT("ModuleRelativePath"), TEXT("PartyGameGameMode.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APartyGameGameMode(Z_Construct_UClass_APartyGameGameMode, &APartyGameGameMode::StaticClass, TEXT("APartyGameGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APartyGameGameMode);
	UFunction* Z_Construct_UFunction_UPartyGameLib_GetRandomColor()
	{
		struct PartyGameLib_eventGetRandomColor_Parms
		{
			FColor ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_UPartyGameLib();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetRandomColor"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04822401, 65535, sizeof(PartyGameLib_eventGetRandomColor_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(ReturnValue, PartyGameLib_eventGetRandomColor_Parms), 0x0010000000000580, Z_Construct_UScriptStruct_FColor());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Colors"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Libs/PartyGameLib.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPartyGameLib_NoRegister()
	{
		return UPartyGameLib::StaticClass();
	}
	UClass* Z_Construct_UClass_UPartyGameLib()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UBlueprintFunctionLibrary();
			Z_Construct_UPackage__Script_PartyGame();
			OuterClass = UPartyGameLib::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20100080;

				OuterClass->LinkChild(Z_Construct_UFunction_UPartyGameLib_GetRandomColor());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UPartyGameLib_GetRandomColor(), "GetRandomColor"); // 4066470715
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Libs/PartyGameLib.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Libs/PartyGameLib.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPartyGameLib(Z_Construct_UClass_UPartyGameLib, &UPartyGameLib::StaticClass, TEXT("UPartyGameLib"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPartyGameLib);
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
	UPackage* Z_Construct_UPackage__Script_PartyGame()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/PartyGame")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x131D577A;
			Guid.B = 0x2310380F;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
