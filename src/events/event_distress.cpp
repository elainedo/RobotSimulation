/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "event_distress.h"

/*******************************************************************************
* Constructor
******************************************************************************/
EventDistress::EventDistress(void) :
    ent_name_("ArenaEntity"),
    position_(0, 0),
    range_(0.0),
    entity_(kEntity) {}

EventDistress::EventDistress(std::string name, Position p,
    double range, enum entity_types entity_type) :

    ent_name_(name),
    position_(p),
    range_(range),
    entity_(entity_type) {}

/*******************************************************************************
* Member Functions
******************************************************************************/
void EventDistress::EmitMessage(void) {
    printf("Sensed a distress call nearby");
} /* EmitMessage() */