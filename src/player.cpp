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
        initial_pos_(params->pos) {

    id_ = next_id_++;
    initial_pos_ = params->pos;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Player::TimestepUpdate(uint dt) {
    Position old_pos = get_pos();

    set_last_pos(get_pos());

} /* TimestepUpdate() */

