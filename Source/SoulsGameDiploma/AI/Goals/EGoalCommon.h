#pragma once

#include "EGoalCommon.generated.h"

/**
 * Enum for common goals shared amongst most enemies.
 */
UENUM(BlueprintType)
enum class EGoalCommon : uint8
{
    // Default
     IDLE                UMETA(DisplayName = "Idle")
    ,CHASE               UMETA(DisplayName = "Chase")
    ,FLEE                UMETA(DisplayName = "Flee")
    
    // Combat
    ,ATTACK              UMETA(DisplayName = "Attack")
    ,COMBO_ATTACK        UMETA(DisplayName = "Combo Attack")
    ,COMBO_REPEAT        UMETA(DisplayName = "Combo Repeat")
    ,COMBO_FINAL         UMETA(DisplayName = "Combo Final")
    ,STRAFE              UMETA(DisplayName = "Strafe")
};

