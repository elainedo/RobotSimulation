/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "motion_behavior.h"
#include "../common/position.h"
#include "../entities/arena_mobile_entity.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionBehavior::UpdatePosition(ArenaMobileEntity * const ent,
                                         unsigned int dt) {
    // Save position for debugging purposes
    Position new_pos = ent->get_pos();

    // Movement is always along the heading_angle (i.e. the hypotenuse)
    new_pos.x(new_pos.x() + cos(ent->get_heading_angle()*M_PI/180.0)*
                ent->get_speed()*dt);
    new_pos.y(new_pos.y() + sin(ent->get_heading_angle()*M_PI/180.0)*
                ent->get_speed()*dt);
    ent->set_pos(new_pos);
}

void MotionBehavior::Accept(__unused const EventCollision * const e) {
}
