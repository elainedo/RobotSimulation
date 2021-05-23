
#include "player_motion_handler.h"


/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
PlayerMotionHandler::PlayerMotionHandler() :
  max_speed_(100),
  max_angle_(360) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void PlayerMotionHandler::AcceptCommand(enum motion_commands cmd) {
    // avoid command if robot is frozen
    if (time_to_unfreeze > 0) return;
    switch (cmd) {
        case kTurnLeft:
            set_heading_angle(get_heading_angle() - 10);
            break;
        case kTurnRight:
            set_heading_angle(get_heading_angle() + 10);
            break;
        case kSpeedUp:
            if (get_speed()+5 <= get_max_speed())
                set_speed(get_speed() + 5);
            else
                set_speed(get_max_speed());
            break;
        case kSlowDown:
            if (get_speed()-5 >= 0)
                set_speed(get_speed() - 5);
            else
                set_speed(0);
            break;
    default:
        std::cerr << "FATAL: bad actuator command" << std::endl;
        assert(0);
    } /* switch() */
} /* accept_command() */

void PlayerMotionHandler::UpdateVelocity(std::vector<class Sensor*> sensors) {
    time_to_unfreeze = time_to_unfreeze - 1;
    if (time_to_unfreeze > 0) return;
    if (time_to_unfreeze == 0) set_speed(5);
    for (auto sensor : sensors) {
        if (sensor->get_type() == kSensorTouch) {
            if (sensor->activated()) {
                if (sensor->get_entity_type() == kSuperBot) {
                    set_speed(0);
                    time_to_unfreeze = 30;
                }
            }
            if (sensor->activated()) {
                set_heading_angle(- sensor->Output());
            }
        }
    }
}
