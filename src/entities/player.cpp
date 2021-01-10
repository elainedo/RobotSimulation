#include "player.h"

uint Player::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Player::Player(const struct player_params* const params) :
    ArenaMobileEntity(params->radius, params->collision_delta,
        params->pos, params->color),

        id_(-1),
        heading_angle_(0),
        angle_delta_(params->angle_delta),
        
        initial_pos_(params->pos),
        motion_handler_(),
        motion_behavior_(),
        sensors_(),
        sensor_touch_(this, this->radius()) {
    id_ = next_id_++;
    initial_pos_ = params->pos;
    motion_handler_.set_heading_angle(0);
    motion_handler_.set_speed(5);
    sensors_.push_back(&sensor_touch_);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Player::TimestepUpdate(uint dt) {
    Position old_pos = get_pos();

    if (sensor_touch_.activated()) {
        set_pos(get_last_pos());
    }
    set_last_pos(get_pos());

    // Update heading and speed as indicated by touch sensor
    motion_handler_.UpdateVelocity(sensors_);

    // Use velocity and position to update position
    motion_behavior_.UpdatePosition(this, dt);

    sensor_touch_.activated(false);

} /* TimestepUpdate() */

void Player::AcceptCommand(enum motion_commands e) {
    motion_handler_.AcceptCommand(e);
}

void Player::Reset(void) {
    motion_handler_.Reset();
    sensor_touch_.Reset();
    set_pos(initial_pos_);
    set_speed(5);
    set_heading_angle(37);
} /* Reset() */

