
#ifndef EVENT_TYPE_H_
#define EVENT_TYPE_H_

/**
 * @brief The supported sensor types.
 */
enum event_types {
    kEventCollision,
    kEventDistress,
    kEventProximity,
    kEventTypeEmit,
    kEventRecharge,
    kEventCommand,
    kEventKeypress,
    kEventBaseClass
};

#endif