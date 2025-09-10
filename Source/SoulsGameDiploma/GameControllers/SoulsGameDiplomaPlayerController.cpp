// Copyright Epic Games, Inc. All Rights Reserved.


#include "SoulsGameDiplomaPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"

void ASoulsGameDiplomaPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ASoulsGameDiplomaPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}
			
		}
	}

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (PauseAction)
		{
			PauseAction->bTriggerWhenPaused = true; // Required!
			EnhancedInput->BindAction(PauseAction, ETriggerEvent::Triggered, this, &ASoulsGameDiplomaPlayerController::Pause);
		}
	}
}

void ASoulsGameDiplomaPlayerController::Pause()
{
	//Super::Pause();
	UE_LOG(LogTemp, Warning, TEXT("SoulsGameDiplomaPlayerController : Pause function"));

	// if (ASoulsHUD* HUD = Cast<ASoulssHUD>(GetHUD()))
	// {
	// 	HUD->PauseMenu();
	// }
	//
}
