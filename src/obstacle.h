/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "arena_immobile_entity.h"
#include "color.h"

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

 private:
    static uint next_id_;
    int id_;
};