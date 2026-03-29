// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyBase.h"
#include "AI/BaseAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CombatAIController.h"
#include "Kismet/GameplayStatics.h"

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

	AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) return;

	//TODO why not use this tick instead of Evaluators tick? We need to trigger transitions manually anyways

	float Distance = FVector::Dist(GetActorLocation(), Player->GetActorLocation());
	if (Distance <= ChaseRadius)
	{
		//SelectedGoal = EGoalCommon::CHASE;
	}
}

bool AEnemyBase::HandleGoalSelection()
{
	AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) {
		return false;
	}

	float Distance = FVector::Dist(GetActorLocation(), Player->GetActorLocation());
	if (Distance > ChaseRadius)
	{
		SelectedGoal = EGoalCommon::IDLE;
	}

	if (Distance <= ChaseRadius && Distance > AttackRadius)
	{
		SelectedGoal = EGoalCommon::CHASE;
	}

	if (Distance < AttackRadius)
	{
		SelectedGoal = EGoalCommon::ATTACK;
	}
	return true;
}

//TODO Change Names to HandleIdleTask or move it completely to STT_Idle cpp file or smth
void AEnemyBase::HandleIdleGoal()
{
	UE_LOG(LogTemp, Warning, TEXT("[EnemyBase.cpp] Idle! Distance: %.1f"));
}

//TODO rename to STT_ChaseTask
void AEnemyBase::HandleChaseGoal()
{
	UE_LOG(LogTemp, Warning, TEXT("[EnemyBase.cpp] Chase!"));
}

