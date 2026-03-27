#pragma once

#include "EGoalCommon.generated.h"

/**
 * Enum for common goals share amongs most enemies.
 */
UENUM(BlueprintType)
enum class EGoalCommon : uint8
{
    IDLE        UMETA(DisplayName = "Idle"),
    CHASE       UMETA(DisplayName = "Chase"),
    ATTACK      UMETA(DisplayName = "Attack"),
    STRAFE      UMETA(DisplayName = "Strafe"),
    FLEE        UMETA(DisplayName = "Flee")
};

