#ifndef SENSOR_TOUCH_H_
#define SENSOR_TOUCH_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "../events/event_collision.h"
#include "sensor.h"
#include "../entities/arena_entity.h"

/*******************************************************************************
 * Classes
 ******************************************************************************/

/**
 * @brief A representation of a touch sensor.
 *
 * Touch or "bump" sensors are "active" when pressed. For our purposes, imagine
 * a series of bump sensors around the perimeter of the robot. A collision will
 * activate the sensor at a particular point of contact, which translates to an
 * angle of contact.
 */
class SensorTouch: public Sensor {
public:
    SensorTouch(ArenaEntity * arena_entity, const double range);

    Position point_of_contact() { return point_of_contact_; }
    void point_of_contact(Position p) {
        point_of_contact_ = p;
    }

    double angle_of_contact(void) { return angle_of_contact_; }
    void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

    void Accept(const EventBaseClass * const e) override;
    /**
     * @brief Compute a new reading based on the collision event.
     *
     * Note that collision events can report "no collision" which
     * will inactivate the sensor.
     *
     */
    void Accept(const EventCollision * const e);

    /**
     * @brief Reset the proximity sensor to its newly constructed state.
     */
    void Reset(void);

    int Output(void) override;

    double get_range(void) const override {
        return range_;
    }

    /**
     * @brief Calculate entity position to determine if entity is colliding withi
     * the walls
     */
    void CheckForEntityOutOfBounds(const EventCollision * const e);

    /**
     * @brief Calculate entity position to determine if 2 entities collide with
     * each other
     */
    void CheckForEntityCollision(const EventCollision * const e);

    /**
     * @brief Get the type of the sensor
     */
    enum sensor_types get_type() const override { return kSensorTouch; }

    /**
     * @brief Get the type of the entity this sensor belongs to
     */
    enum entity_types get_entity_type(void) const override {
        return entity_type_emit_;
    }


private:
    Position point_of_contact_;
    double angle_of_contact_;
    double range_;
    int heading_angle_;
    enum entity_types entity_type_emit_;

    double Positive(double angle);
};

#endif 