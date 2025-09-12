// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SoulsGameDiplomaPlayerController.generated.h"

class UInputMappingContext;

/**
 *  PlayerController class for a souls game
 *  Manages input mappings
 */
UCLASS(abstract)
class ASoulsGameDiplomaPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category ="Input | Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;
	
	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	/** Gameplay initialization */
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(EditDefaultsOnly, Category ="Input | Input Mappings")
	class UInputAction* PauseAction;
	void Pause();	

};
