#ifndef PLAYER_PARAMS_H
#define PLAYER_PARAMS_H

#include "arena_mobile_entity_params.h"

struct player_params : public arena_mobile_entity_params {
    player_params(void) :
        arena_mobile_entity_params(),
        battery_max_charge(),
        angle_delta(),
        pos() {}

    double battery_max_charge;
    int angle_delta;
    Position pos;
};

#endif