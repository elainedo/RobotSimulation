#ifndef PLAYER_MOTION_HANDLER_H_
#define PLAYER_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "motion_commands.h"
#include "../events/event_collision.h"
#include "../events/event_key_press.h"
#include "../params/player_params.h"
#include "../entities/arena_mobile_entity.h"
#include "../sensors/sensor_touch.h"
#include "motion_handler.h"
/**
 * @brief The handler for the player's actuators. A player should bounce off if
 * it collides with robot, home base, wall and recharge station and be frozen
 * if it collides with SuperBot
 */
class PlayerMotionHandler: public MotionHandler {
public:
    PlayerMotionHandler(void);

    /**
     * @brief Reset the actuators to their newly constructed/un-commanded state.
     */
    void Reset(void) {
        set_max_speed(100);
        set_max_angle(360);
    }

    /**
     * @brief Change the speed and direction according to the sensor readings.
     *
     * @param a vector of sensors; determine speed and heading angle based off of
     * information from sensors
     *
     */
    void UpdateVelocity(std::vector<class Sensor*> sensors);

    void Accept(const EventKeypress * const e);

    void AcceptCommand(enum motion_commands cmd);

    double get_max_angle(void) const override { return max_angle_; }
    void set_max_angle(double ma) override { max_angle_ = ma; }

    double get_max_speed(void) const override { return max_speed_; }
    void set_max_speed(double ms) override { max_speed_ = ms; }

private:
    double max_speed_;
    double max_angle_;
    int time_to_unfreeze = 0;  // if time_to_unfreeze > 0, robot motion handler
                                // does not accept command
};

#endif
