// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lab_Statefull.h"

#define LOCTEXT_NAMESPACE "FLab_StatefullModule"

void FLab_StatefullModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FLab_StatefullModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLab_StatefullModule, Lab_Statefull)