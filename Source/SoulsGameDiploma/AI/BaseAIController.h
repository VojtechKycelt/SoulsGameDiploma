// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

class UStateTreeAIComponent;

/**
 *	Abstract basic AI Controller for Enemies, capable of running StateTree.
 */
UCLASS(abstract)
class SOULSGAMEDIPLOMA_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

	/** StateTree Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStateTreeAIComponent* StateTreeAI;

public:

	/** Constructor */
	ABaseAIController();
};