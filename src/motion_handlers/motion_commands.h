
#ifndef MOTION_COMMANDS_H_
#define MOTION_COMMANDS_H_

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * @brief The supported commands that the robot supports: forward, turn left and turn right.
 */
enum motion_commands {
    kInvalid,
    kTurnLeft,
    kTurnRight,
    kSpeedUp,
    kSlowDown
};


#endif
