// Copyright Epic Games, Inc. All Rights Reserved.

#include "Hospes_CPPGameMode.h"
#include "Hospes_CPPPlayerController.h"
#include "Hospes_CPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHospes_CPPGameMode::AHospes_CPPGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHospes_CPPPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}