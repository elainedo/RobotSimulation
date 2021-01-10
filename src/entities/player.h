#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "arena_mobile_entity.h"
#include "../params/player_params.h"
#include "../motion_handlers/motion_commands.h"
#include "../motion_handlers/player_motion_handler.h"
#include "../motion_handlers/motion_behavior.h"
#include "../sensors/sensor_touch.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a mobile robot within the arena.
 *
 * Robots have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 */
class Player : public ArenaMobileEntity {
public:
    explicit Player(const struct player_params* const params);

    /**
     * @brief Reset the robot to a newly constructed state (needed for reset
     * button to work in arena GUI).
     */
    void Reset(void) override;

    /**
     * @brief Update the robot's position and velocity after the specified
     * duration has passed.
     *
     * @param dt The # of timesteps that have elapsed since the last update.
     */
    void TimestepUpdate(unsigned int dt) override;


    /**
     * @brief  Pass along a command event (from arena) to the motio handler.
     *
     * This method provides a framework in which sensors motion handler receives
     * different types of commands and change handing angle and velocity
     * accordingly
     *
     * @param e event_commands.
     */
    void AcceptCommand(enum motion_commands e);

    double get_heading_angle(void) const override {
        return motion_handler_.get_heading_angle();
    }

    void set_heading_angle(double ha) override {
        motion_handler_.set_heading_angle(ha);
    }

    double get_speed(void) const override {
        return motion_handler_.get_speed();
    }
    
    void set_speed(double sp) override {
        motion_handler_.set_speed(sp);
    }

    std::string get_name(void) const override {
        return "Player" + std::to_string(id_);
    }

    enum entity_types get_type() const override { return kPlayer; }

 private:
    static unsigned int next_id_;

    int id_;
    double heading_angle_;
    double angle_delta_;
    Position initial_pos_;

    std::vector<class Sensor*> sensors_;
    SensorTouch sensor_touch_;

    PlayerMotionHandler motion_handler_;
    MotionBehavior motion_behavior_;
};

#endif