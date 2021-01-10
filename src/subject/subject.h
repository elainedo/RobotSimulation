#ifndef SUBJECT_H_
#define SUBJECT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "../events/event_base_class.h"
#include "../sensors/sensor.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A class that stores sensors, registers sensors and sends event to
 * accept function in arena
 *
 */

class Subject {
public:
    Subject(void):
        max_range_(0),
        observers_() {}

    virtual ~Subject(void) {}

    virtual void RegisterObserver(Sensor * sensor);
    virtual void StateChange(const EventBaseClass * const event);
    virtual void Notify(const EventBaseClass * const event);
private:
    int max_range_;
    std::vector<class Sensor*> observers_;
};

#endif