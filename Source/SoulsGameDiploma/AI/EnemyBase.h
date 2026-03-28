// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI/Goals/EGoalCommon.h"
#include "EnemyBase.generated.h"

UCLASS()
class AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Goals Handlers
	UFUNCTION(BlueprintCallable, Category = "AI")
	virtual void HandleIdleGoal();

	UFUNCTION(BlueprintCallable, Category = "AI")
	virtual void HandleChaseGoal();

protected:

	// Max amount of HP the character will have on respawn.
	UPROPERTY(EditAnywhere, Category = "Stats")
	float MaxHP = 100.0f;

public:
	/** STATS */

	// Current amount of HP
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ClampMin = 0))
	float CurrentHP = 0.0f;

	// Base amount of Attack Damage the character can deal, used for dealing damage calculations in combat
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats", meta = (ClampMin = 0))
	float BaseAttackDamage = 25.0f;

	// Base amount of Armor the character has, used for receiving damage calculations in combat
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ClampMin = 0))
	float BaseArmor = 10.0f;

	// Base amount of Fire resistance the character has, used for receiving fire damage calculations in combat
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ClampMin = 0))
	float BaseFireResistance = 5.0f;

	/** AI PROPERTIES */
	
	// Base amount of Fire resistance the character has, used for receiving fire damage calculations in combat
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	float ChaseRadius = 1000.0f;

	// Base amount of Fire resistance the character has, used for receiving fire damage calculations in combat
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	float AttackRadius = 300.0f;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	EGoalCommon SelectedGoal;
};
