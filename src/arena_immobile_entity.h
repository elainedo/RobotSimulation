
#include "arena_entity.h"
#include "color.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An immobile entity in the arena.
 *
 * Immobile entities cannot move, and therefore do not need to override the
 * \ref TimestepUpdate() function.
 */

class ArenaImmobileEntity : public ArenaEntity {
 public:
  ArenaImmobileEntity(double radius, const Position& pos,
                    const Color& color) :
      ArenaEntity(radius, pos, color) {}
};
