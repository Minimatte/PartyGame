// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PARTYGAME_PartyGameGameMode_generated_h
#error "PartyGameGameMode.generated.h already included, missing '#pragma once' in PartyGameGameMode.h"
#endif
#define PARTYGAME_PartyGameGameMode_generated_h

#define PartyGame_Source_PartyGame_PartyGameGameMode_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreatePlayer) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CreatePlayer(); \
		P_NATIVE_END; \
	}


#define PartyGame_Source_PartyGame_PartyGameGameMode_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreatePlayer) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CreatePlayer(); \
		P_NATIVE_END; \
	}


#define PartyGame_Source_PartyGame_PartyGameGameMode_h_14_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAPartyGameGameMode(); \
	friend PARTYGAME_API class UClass* Z_Construct_UClass_APartyGameGameMode(); \
	public: \
	DECLARE_CLASS(APartyGameGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/PartyGame"), NO_API) \
	DECLARE_SERIALIZER(APartyGameGameMode) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PartyGame_Source_PartyGame_PartyGameGameMode_h_14_INCLASS \
	private: \
	static void StaticRegisterNativesAPartyGameGameMode(); \
	friend PARTYGAME_API class UClass* Z_Construct_UClass_APartyGameGameMode(); \
	public: \
	DECLARE_CLASS(APartyGameGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/PartyGame"), NO_API) \
	DECLARE_SERIALIZER(APartyGameGameMode) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PartyGame_Source_PartyGame_PartyGameGameMode_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APartyGameGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APartyGameGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APartyGameGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APartyGameGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APartyGameGameMode(APartyGameGameMode&&); \
	NO_API APartyGameGameMode(const APartyGameGameMode&); \
public:


#define PartyGame_Source_PartyGame_PartyGameGameMode_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APartyGameGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APartyGameGameMode(APartyGameGameMode&&); \
	NO_API APartyGameGameMode(const APartyGameGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APartyGameGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APartyGameGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APartyGameGameMode)


#define PartyGame_Source_PartyGame_PartyGameGameMode_h_11_PROLOG
#define PartyGame_Source_PartyGame_PartyGameGameMode_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PartyGame_Source_PartyGame_PartyGameGameMode_h_14_RPC_WRAPPERS \
	PartyGame_Source_PartyGame_PartyGameGameMode_h_14_INCLASS \
	PartyGame_Source_PartyGame_PartyGameGameMode_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PartyGame_Source_PartyGame_PartyGameGameMode_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PartyGame_Source_PartyGame_PartyGameGameMode_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	PartyGame_Source_PartyGame_PartyGameGameMode_h_14_INCLASS_NO_PURE_DECLS \
	PartyGame_Source_PartyGame_PartyGameGameMode_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PartyGame_Source_PartyGame_PartyGameGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
