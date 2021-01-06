#ifndef ARENA_ENTITY_PARAMS_H
#define ARENA_ENTITY_PARAMS_H

#include "position.h"
#include "color.h"

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
 /**
  * @brief Define the parameters for an entity within the arena.
  */
struct arena_entity_params {
  arena_entity_params(void) : radius(), pos(), color() {}
  double radius;
  Position pos;
  Color color;
};

#endif
