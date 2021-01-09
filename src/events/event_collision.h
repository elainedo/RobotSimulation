#ifndef EVENT_COLLISION_H_
#define EVENT_COLLISION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include <string>
#include "event_base_class.h"
#include "../common/position.h"
#include "../entities/entity_types.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A collision event class, which is created after a
 * \ref MobileArenaEntity gets within a specified distance of another entity in
 * the arena, OR when an entity that was previously within the collision delta
 * of other entity outside of that threshold.
 */
class EventCollision : public EventBaseClass {
public:
    EventCollision(void);

    EventCollision(std::string name, Position pos,
                double range, enum entity_types entity_type);

    EventCollision(double x_dim, double y_dim, enum entity_types entity_type);

    void EmitMessage(void) override;

    /**
     * @brief If \c TRUE, then this instance represents an active collision
     * event. If \c FALSE, then it represents a previous collision event that has
     * been resolved.
     */
    bool collided(void) const { return collided_; }
    void collided(bool c) { collided_ = c; }

    /**
     * @brief The point in the arena at which the entities have collided/touched.
     */
    Position point_of_contact(void) const { return point_of_contact_; }
    void point_of_contact(Position p) { point_of_contact_ = p; }

    /**
     * @brief The angle, in degrees, as specified on the unit circle, that the
     * collision occurred at. Needed to calculate the outgoing/bounceback angle.
     */
    double angle_of_contact(void) const { return angle_of_contact_; }
    void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

    /**
     * @brief Position where the event happends
     */
    void set_pos(const Position& pos) { position_ = pos; }
    const Position& get_pos(void) const {
        return position_;
    }

    /**
     * @brief Get entity name that this event is reading from
     */
    std::string get_ent_name() const { return ent_name_; }

    /**
     * @brief Get type of this event
     */
    enum event_types get_type() const override { return kEventCollision; }

    /**
     * @brief Get entity type that this event is reading from
     */
    enum entity_types get_entity_type() const override { return entity_; }

    /**
     * @brief Get the range of this event
     */
    double get_range(void) const { return range_; }

    /**
     * @brief Set the range of this event
     */
    void set_range(double r) { range_ = r; }

    /**
     * @brief Get the x dimension of arena, which aids determining collision with
     * walls
     */
    double get_x_dim(void) const { return x_dim_; }

    /**
     * @brief Get the y dimension of arena, which aids determining collision with
     * walls
     */
    double get_y_dim(void) const { return y_dim_; }

private:
    bool collided_;
    Position point_of_contact_;
    double angle_of_contact_;
    std::string ent_name_;
    Position position_;
    double range_;
    enum entity_types entity_;

    double x_dim_;  // used to check if entities collide with walls
    double y_dim_;
};

#endif