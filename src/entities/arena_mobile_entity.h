#ifndef ARENA_MOBILE_ENTITY_H
#define ARENA_MOBILE_ENTITY_H

#include <algorithm>
#include "arena_entity.h"
#include "../common/color.h"

class ArenaMobileEntity : public ArenaEntity {
public:
    ArenaMobileEntity(double radius, double collision_delta,
        const Position& pos, const Color& color) :
            ArenaEntity(radius, pos, color),
            collision_delta_(collision_delta),
            last_pos_(pos) {}

    /**
     * @brief Get the current heading angle for the entity.
     */
    virtual double get_heading_angle(void) const = 0;

    /**
     * @brief Set the new heading angle for the entity.
     *
     * This should only be called by a dedicated motion handler class, and only
     * from within \ref Timestepupdate().
     */
    virtual void set_heading_angle(double heading_angle) = 0;

    /**
     * @brief Get the current speed of an arena entity.
     */
    virtual double get_speed(void) const = 0;

    /**
     * @brief Set the new speed of an entity.
     *
     * This should only be called by a dedicated motion handler class, and only
     * from within \ref Timestepupdate().
     */
    virtual void set_speed(double sp) = 0;

    /**
     * @brief Update an entity's position and velocity after the specified # of
     * timesteps has elapsed.
     *
     * @param dt The # of timesteps that has elapsed since the last time
     * position/velocity were updated.
     */
    virtual void TimestepUpdate(uint dt) override {}

    /**
     * @brief Get the minimum distance between two arena entities that will be
     * considered a collision.
     *
     */
    double collision_delta(void) const { return collision_delta_; }

    /**
     * @brief Get the last position before current timestep
     *
     */
    Position get_last_pos(void) { return last_pos_; }

    /**
     * @brief Set last position to be a new updated one
     *
     */
    void set_last_pos(Position p) { last_pos_ = p; }

private:
    double collision_delta_;
    Position last_pos_;
};

#endif