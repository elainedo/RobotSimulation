/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "subject.h"

void Subject::RegisterObserver(Sensor * sensor) {
    observers_.push_back(sensor);
    if (sensor->get_range() > max_range_) {
        max_range_ = sensor->get_range();
    }
}

void Subject::Notify(const EventBaseClass * const event) {
    for (auto obs : observers_) {
        obs->Accept(event);
    }
}

void Subject::StateChange(const EventBaseClass * const event) {
    Notify(event);
}
