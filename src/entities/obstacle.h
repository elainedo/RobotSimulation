/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "arena_immobile_entity.h"
#include "../common/color.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief A class representing an obstacle within the arena.
  */
class Obstacle: public ArenaImmobileEntity {
public:
    Obstacle(double radius, const Position& pos,
                    const Color& color);

    std::string get_name(void) const override {
        return "Obstacle" + std::to_string(id_);
    }

    enum entity_types get_type() const override { return kObstacle; }

 private:
    static uint next_id_;
    int id_;
};