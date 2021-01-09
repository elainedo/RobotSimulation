/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include <cmath>
#include "sensor_touch.h"
#include "../entities/arena_entity.h"
#include "../entities/arena_mobile_entity.h"

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorTouch::SensorTouch(ArenaEntity * arena_entity, const double range) :
    Sensor(arena_entity),
    point_of_contact_(0, 0),
    angle_of_contact_(0),
    range_(range),
    heading_angle_(0),
    entity_type_emit_(kEntity) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void SensorTouch::Accept(const EventBaseClass * const e) {
    if (e->get_type() == kEventCollision) {
        EventCollision *event = const_cast<EventCollision*>
        (reinterpret_cast<const EventCollision*> (e));
        Accept(event);
    }
}

void SensorTouch::Accept(const EventCollision * const e) {
    if (get_arena_entity()->get_name() == e->get_ent_name()) {
        return;
    }
    if (e->get_entity_type() == kWall) {
        CheckForEntityOutOfBounds(e);
        return;
    }
    CheckForEntityCollision(e);
}

void SensorTouch::CheckForEntityOutOfBounds(const EventCollision * const e) {
    ArenaMobileEntity *arena_mobile_entity = const_cast<ArenaMobileEntity*>
        (reinterpret_cast<const ArenaMobileEntity*> (get_arena_entity()));
    if (arena_mobile_entity->get_pos().x() + arena_mobile_entity->radius() >
                                                                e->get_x_dim()) {
        activated(true);
        heading_angle_ =
                    static_cast<int> (arena_mobile_entity->get_heading_angle()+180);
        entity_type_emit_ = e->get_entity_type();
    } else if (arena_mobile_entity->get_pos().x() -
                                arena_mobile_entity->radius() < 0) {  // Left Wall
        // std::cout << "Left Wall" << std::endl;
        activated(true);
        heading_angle_ =
                    static_cast<int> (arena_mobile_entity->get_heading_angle()+180);
        entity_type_emit_ = e->get_entity_type();
    } else if (arena_mobile_entity->get_pos().y() + arena_mobile_entity->radius()
                                            > e->get_y_dim()) {  // Bottom Wall
        // std::cout << "Bottom Wall" << std::endl;
        activated(true);
        heading_angle_ =
                    static_cast<int> (arena_mobile_entity->get_heading_angle());
        entity_type_emit_ = e->get_entity_type();
    } else if (arena_mobile_entity->get_pos().y() -
                                arena_mobile_entity->radius() < 100) {  // Top Wall
        // std::cout << "Top Wall" << std::endl;
        activated(true);
        heading_angle_ =
                    static_cast<int> (arena_mobile_entity->get_heading_angle());
        entity_type_emit_ = e->get_entity_type();
    }
    return;
}

void SensorTouch::CheckForEntityCollision(const EventCollision * const e) {
    double ent1_x = get_arena_entity()->get_pos().x();
    double ent1_y = get_arena_entity()->get_pos().y();
    double ent2_x = e->get_pos().x();
    double ent2_y = e->get_pos().y();
    double dist = std::sqrt(std::pow(ent2_x - ent1_x, 2) +
                            std::pow(ent2_y - ent1_y, 2));
    if (dist <= e->get_range() + range_) {
        activated(true);
        entity_type_emit_ = e->get_entity_type();
        double angle = std::asin(std::abs(ent2_x - ent1_x) / dist);

        if ((ent2_x - ent1_x) > 0) {
            if ((ent2_y - ent1_y) > 0) {
                // lower right
                angle = M_PI_2 - angle;
            } else if ((ent2_y - ent1_y) < 0) {
                // upper right
                angle += (3 * M_PI_2);
            } else {  // if ((ent2_y - ent1_y) == 0)
                // 0 or 360 deg
                angle = 0;
            }
        } else if ((ent2_x - ent1_x) < 0)  {
            if ((ent2_y - ent1_y) > 0) {
                // lower left
                angle += M_PI_2;
            } else if ((ent2_y - ent1_y) < 0) {
                // upper left
                angle = (M_PI_2 * 2) + (M_PI_2 - angle);
            } else {  // if ((ent2_y - ent1_y) == 0)
                // 180 deg
                angle = M_PI;
            }
            } else {  // if ((ent2_x - ent1_x) == 0)
            if ((ent2_y - ent1_y) > 0) {
                // 90 deg
                angle = M_PI_2;
            } else if ((ent2_y - ent1_y) < 0) {
                // 270 deg
                angle = (3 * M_PI_2);
            } else {  // if ((ent2_y - ent1_y) == 0)
                // completely overlap, which is theoretically impossible...
                assert(false);
            }
        }
        heading_angle_ = static_cast<int> ((M_PI - angle) / M_PI * 180);
    }
}

int SensorTouch::Output(void) {
    return heading_angle_;
}

double SensorTouch::Positive(double angle) {
    while (angle < 0) {
        angle = angle + 360;
    }
    while (angle > 360) {
        angle = angle - 360;
    }
    return angle;
}

void SensorTouch::Reset(void) {
    activated(false);
    point_of_contact_ = Position(0, 0);
    angle_of_contact_ = 0;
} /* reset() */
