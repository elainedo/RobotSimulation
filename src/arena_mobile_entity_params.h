#ifndef ARENA_MOBILE_ENTITY_PARAMS_H
#define ARENA_MOBILE_ENTITY_PARAMS_H

#include "arena_entity_params.h"

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @brief Define the parameters for a mobile entity within the arena.
 */
struct arena_mobile_entity_params : public arena_entity_params {
    arena_mobile_entity_params(void) : arena_entity_params(), 
    collision_delta() {}

    /**
     * @brief Minimum distance between entities that qualifies as a collision.
     */
    double collision_delta;
};

#endif