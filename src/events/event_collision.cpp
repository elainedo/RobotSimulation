/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "event_collision.h"

/*******************************************************************************
 * Constructor
 ******************************************************************************/
EventCollision::EventCollision() :
    collided_(false),
    point_of_contact_(0, 0),
    angle_of_contact_(0),
    ent_name_("ArenaEntity"),
    position_(0, 0),
    range_(0.0),
    entity_(kEntity),
    x_dim_(0.0),
    y_dim_(0.0) {
}

EventCollision::EventCollision(std::string name, Position pos,
                  double range, enum entity_types entity_type) :
    collided_(false),
    point_of_contact_(0, 0),
    angle_of_contact_(0),
    ent_name_(name),
    position_(pos),
    range_(range),
    entity_(entity_type),
    x_dim_(0.0),
    y_dim_(0.0) {
}

EventCollision::EventCollision(double x_dim, double y_dim,
                            enum entity_types entity_type) :
    collided_(false),
    point_of_contact_(0, 0),
    angle_of_contact_(0),
    ent_name_("ArenaEntity"),
    position_(0, 0),
    range_(0.0),
    entity_(entity_type),
    x_dim_(x_dim),
    y_dim_(y_dim) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void EventCollision::EmitMessage(void) {
  printf("Collision event at point %f %f. Angle %f",
         point_of_contact_.x(), point_of_contact_.y(),
         angle_of_contact_);
} /* EmitMessage() */
