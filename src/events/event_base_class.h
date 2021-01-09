
#ifndef EVENT_BASE_CLASS_H_
#define EVENT_BASE_CLASS_H_

#include "event_types.h"
#include "../entities/entity_types.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base event class from which all events should derive from.
 */
class EventBaseClass {
public:
    EventBaseClass(void) :
        entity_type_(kEntity) {}

    explicit EventBaseClass(enum entity_types entity_type) :
        entity_type_(entity_type) {}

    virtual ~EventBaseClass(void) {}

    /**
     * @brief Each event, upon its firing, should emit a message to the user on
     * stdout saying what happened, in order to aid debugging.
     *
     */
    virtual void EmitMessage(void) = 0;

    /**
     * @brief Get type of the event
     */
    virtual enum event_types get_type() const = 0;

    /**
     * @brief Get type of the event that this event is reading from
     */
    virtual enum entity_types get_entity_type() const {
        return entity_type_;
    }

private:
    enum entity_types entity_type_;
};

#endif