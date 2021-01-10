#ifndef EVENT_DISTRESS_H_
#define EVENT_DISTRESS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <string>
#include "event_base_class.h"
#include "../entities/entity_types.h"
#include "../common/position.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An event representing a distress call. If a robot senses a distress
 * call via distress event, it will ignore its proximity sensor.
 */
class EventDistress : public EventBaseClass {
public:
    EventDistress(void);

    EventDistress(std::string name, Position p,
        double range, enum entity_types entity_type);

    void EmitMessage(void) override;

    /**
     * @brief Position where the event happends
     */
    void set_pos(const Position& pos) { position_ = pos; }
    const Position& get_pos(void) const {
        return position_;
    }

    void set_entity(enum entity_types ent) { entity_ = ent; }
    enum entity_types get_entity() { return entity_; }

    std::string get_ent_name() const { return ent_name_; }

    /**
     * @brief Get the range of this event
     */
    double get_range(void) const { return range_; }

    /**
     * @brief Get type of this event
     */
    enum event_types get_type() const override { return kEventDistress; }

private:
    std::string ent_name_;
    Position position_;
    double range_;
    enum entity_types entity_;
};

#endif 