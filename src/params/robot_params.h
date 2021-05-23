#ifndef ROBOT_PARAMS_H_
#define ROBOT_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "arena_mobile_entity_params.h"

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
 /**
  * @brief Inherits from mobile_entity_params to set various
  * properties of the robot.
  **/
struct robot_params : public arena_mobile_entity_params {
    robot_params(void) :
        arena_mobile_entity_params() {}
};

#endif 
