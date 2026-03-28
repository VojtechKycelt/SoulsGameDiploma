// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyBase.h"
#include "AI/BaseAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CombatAIController.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set the AI Controller class by default
	AIControllerClass = ABaseAIController::StaticClass();
	//AIControllerClass = ACombatAIController::StaticClass();

	// use an AI Controller regardless of whether we're placed or spawned
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	// ignore the controller's yaw rotation
	bUseControllerRotationYaw = false;

	// set the character movement properties
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	
	// Set initial goal to IDLE
	SelectedGoal = EGoalCommon::IDLE;

	// Set initial HP to maximum
	CurrentHP = MaxHP;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//UE_LOG(LogTemp, Warning, TEXT("Tick is running! DeltaTime: %f"), DeltaTime);

}

void AEnemyBase::HandleIdleGoal()
{
	// Compute probabilities for each action applicable to the IDLE goal

	// Spin the probability wheel to select an action

	UE_LOG(LogTemp, Warning, TEXT("Idle!"));
}

void AEnemyBase::HandleChaseGoal()
{
	//UE_LOG(LogTemp, Warning, TEXT("Handling CHASE goal!"));
	auto* MoveComp = GetCharacterMovement();
	UE_LOG(LogTemp, Warning, TEXT("Chase!"));

	UE_LOG(LogTemp, Warning, TEXT("MaxWalkSpeed: %f"), MoveComp->MaxWalkSpeed);
	UE_LOG(LogTemp, Warning, TEXT("Velocity Size: %f"), GetVelocity().Size());
	UE_LOG(LogTemp, Warning, TEXT("GetMaxSpeed(): %f"), MoveComp->GetMaxSpeed());
}

