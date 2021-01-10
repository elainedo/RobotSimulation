#ifndef PLAYER_BATTERY_H_
#define PLAYER_BATTERY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "../events/event_collision.h"
#include "../sensors/sensor_touch.h"

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief The battery for the player.
 * @todo: implement depletion for movement and collision
 */
class PlayerBattery {
public:
  explicit PlayerBattery(double max_charge) : charge_(max_charge),
                                                max_charge_(max_charge) {}

    /**
     * @brief All robots consume SOME power, even when just sitting there not moving.
     */
    double kBASE_DEPLETION = 0.1;

    /**
     * @brief The amount of energy consumed by the robot due to its linear speed
     * its is directly proportional to that speed, with a scaling factor.
     */
    double kLINEAR_SCALE_FACTOR = 0.01;

    /**
     * @brief The amount of energy consumed by the robot due to its angular speed
     * its is directly proportional to that speed, with a scaling factor.
     */
    double kANGULAR_SCALE_FACTOR = 0.01;

    /**
     * @brief Get the current battery level.
     */
    double level(void) const { return charge_; }

    /**
     * @brief Handle a recharge event by instantly restoring the robot's battery
     * to its maximum value.
     */
    void EventRecharge(void) {
        charge_ = max_charge_;
    }

    /**
     * @brief Reset the robot's battery to its newly constructed/undepleted state.
     */
    void Reset(void) { EventRecharge(); }

    /**
     * @brief Calculate the new battery level based on the current linear/angular speed.
     *
     * @param old_pos The current position.
     * @param angular_vel The position after updated.
     * @param dt Length of time robot moves in 2 positions.
     *
     * @return The updated battery level.
     */
    double Deplete(__unused Position old_pos,
        __unused Position new_pos, __unused double dt);

    /**
     * @brief Calculate the new battery level based on the current linear/angular speed
     * and if robot is colliding with recharge station
     *
     * @param sensor_touch check if robot is colliding with recharge station
     * @param old_pos The current position.
     * @param angular_vel The position after updated.
     * @param dt Length of time robot moves in 2 positions.
     *
     * @return The updated battery level.
     */
    double UpdateBatteryLevel(SensorTouch sensor_touch, __unused Position old_pos,
        __unused Position new_pos, __unused double dt);

    // This is how the battery can be informed a collision occured.
    // Deplete accordingly.
    void Accept(const EventCollision * const e);

private:
    double charge_;
    double max_charge_;
};

#endif 