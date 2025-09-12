// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SoulsCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SOULSGAMEDIPLOMA_API USoulsCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character State")
	bool isRolling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character State")
	bool isAttacking;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character State")
	// bool isJumping;

	// Recovering after getting hit
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character State")
	// bool isRecovering; 
};
