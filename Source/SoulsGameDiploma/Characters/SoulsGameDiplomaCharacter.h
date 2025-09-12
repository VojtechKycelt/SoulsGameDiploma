// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SoulsCharacterAnimInstance.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "SoulsGameDiplomaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(abstract)
class ASoulsGameDiplomaCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
protected:

	/** Input Actions for binding to correct functions */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* RollAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LightAttackAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* HeavyAttackAction;

	
	/** Animation Montages to easily and correctly assign animation to correct action **/
	UPROPERTY(EditAnywhere, Category="Animation")
	UAnimMontage* RollAnimMontage;
	UPROPERTY(EditAnywhere, Category="Animation")
	UAnimMontage* LightAttackAnimMontage;
	UPROPERTY(EditAnywhere, Category="Animation")
	UAnimMontage* HeavyAttackAnimMontage;

	USoulsCharacterAnimInstance* AnimInstance;

	bool CanPerformAction();

	virtual void BeginPlay() override;
	
	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for rolling input */
	void Roll(const FInputActionValue& Value);

	/** Called for attacking inputs */
	void LightAttack(const FInputActionValue& Value);
	void HeavyAttack(const FInputActionValue& Value);

	/** Wrapper function for Jump to decline jump if there is conditions preventing it (like rolling) */
	void SoulsJump(const FInputActionValue& Value);

public:

	/** Constructor */
	ASoulsGameDiplomaCharacter();	
	
	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);
	
	/** Handles look inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);
	
	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();
	
	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();
	
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

