#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "arena_mobile_entity.h"
#include "../params/player_params.h"

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
     * @brief Update the robot's position and velocity after the specified
     * duration has passed.
     *
     * @param dt The # of timesteps that have elapsed since the last update.
     */
    void TimestepUpdate(uint dt) override;

    double get_heading_angle(void) const override {
        return 0;
    }

    void set_heading_angle(double ha) override {
        
    }

    double get_speed(void) const override {
        return 0;
    }
    
    void set_speed(double sp) override {
        
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
};

#endif