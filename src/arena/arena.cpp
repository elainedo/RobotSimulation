/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <cmath>

#include "arena.h"
#include "../entities/player.h"
#include "../entities/obstacle.h"

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena(const struct arena_params* const params) :
    x_dim_(params->x_dim), y_dim_(params->y_dim),
    n_robots_(params->n_robots),
    n_obstacles_(params->n_obstacles),
    player_(new Player(&params->player)),
    entities_(),
    mobile_entities_() {

    for (size_t i = 0; i < n_obstacles_; ++i) {
        entities_.push_back(new Obstacle(
            params->obstacles[i].radius,
            params->obstacles[i].pos,
            params->obstacles[i].color));
  } /* for(i..) */

  entities_.push_back(player_);
  mobile_entities_.push_back(player_);
  player_->set_heading_angle(37);
}

void Arena::AdvanceTime(double dt) {
  if (dt == 0)
    return;
  for (auto ent : entities_) {
      ent->TimestepUpdate(1);
  } 
} /* AdvanceTime() */


void Arena::Accept(const __unused EventKeypress * const e) {
    player_->AcceptCommand(e->get_cmd());
} /* changes functionality of player when user presses special keys*/


void Arena::Reset(void) {
  for (auto ent : entities_) {
    ent->Reset();
  } /* for(ent..) */
  win_ = false;
  lose_ = false;
} /* reset() */

Arena::~Arena(void) {
  for (auto ent : entities_) {
    delete ent;
  } 
}

std::vector<Obstacle*> Arena::obstacles(void) {
  std::vector<Obstacle*> res;
  for (auto ent : entities_) {
    Obstacle* o = dynamic_cast<Obstacle*>(ent);
    if (o) {
      res.push_back(o);
    }
  }
  return res;
}
