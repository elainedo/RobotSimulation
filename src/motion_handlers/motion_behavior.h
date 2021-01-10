#ifndef MOTION_BEHAVIOR_H_
#define MOTION_BEHAVIOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <math.h>
#include "../events/event_collision.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Manages the modification to the velocity based on user
 * input and collisions.
 *
 * Translates velocity and position to a new position. Both of these are
 * straightforward, but the framework allows for more sophisticated models of
 * motion in which each wheel has distinct speed.
 */
class MotionBehavior {
public:
  MotionBehavior(void) {}

    /**
     * @brief Update the position for an ArenaEntity, based on its current
     * position and velocity.
     *
     * @param[in] ent The entitity to update.
     */
    void UpdatePosition(class ArenaMobileEntity * const ent, unsigned int dt);

    void Accept(const EventCollision * const e);
};

#endif