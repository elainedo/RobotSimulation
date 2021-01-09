#ifndef SENSOR_H_
#define SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../events/event_base_class.h"
#include "sensor_types.h"
#include "../entities/arena_entity.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A sensor base classs representing different kinds of sensors.
 *
 * There would be some kinds of sensors derived from this class. Sensor touch
 * is an example.
 * \ref TimestepUpdate() function.
 */

class Sensor {
public:
    explicit Sensor(const ArenaEntity * arena_entity) :
        activated_(false),
        arena_entity_(arena_entity) {}

    Sensor(const Sensor& sensor) :
        activated_(sensor.activated_),
        arena_entity_(sensor.arena_entity_) {}

    Sensor& operator=(const Sensor& sensor) {
        if (this != &sensor) {
        activated_ = sensor.activated_;
        arena_entity_ = sensor.arena_entity_;
        }
        return *this;
    }

    virtual ~Sensor(void) {}

    /**
     * @brief Get the current activation reading from the sensor.
     */
    bool activated(void) { return activated_; }
    void activated(bool activated) { activated_ = activated; }

    const ArenaEntity* get_arena_entity(void) const {
        return arena_entity_;
    }

    virtual int Output(void) = 0;

    virtual double get_range(void) const = 0;

    virtual enum sensor_types get_type() const = 0;

    virtual void Accept(const EventBaseClass * const e) = 0;

    virtual entity_types get_entity_type(void) const = 0;

private:
    bool activated_;
    const ArenaEntity* arena_entity_;
};

#endif