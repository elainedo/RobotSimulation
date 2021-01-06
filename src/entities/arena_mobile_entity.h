#include <algorithm>
#include "arena_entity.h"
#include "../common/color.h"

class ArenaMobileEntity : public ArenaEntity {
public:
    ArenaMobileEntity(double radius, double collision_delta,
        const Position& pos, const Color& color) :
            ArenaEntity(radius, pos, color),
            collision_delta_(collision_delta),
            last_pos_(pos) {}

    /**
     * @brief Perform whatever updates are needed for a particular entity after 1
     * timestep (updating position, changing color, etc.).
     */
    virtual void TimestepUpdate(__unused uint dt) override {}

    /**
     * @brief Get the minimum distance between two arena entities that will be
     * considered a collision.
     *
     */
    double collision_delta(void) const { return collision_delta_; }

    /**
     * @brief Get the last position before current timestep
     *
     */
    Position get_last_pos(void) { return last_pos_; }

    /**
     * @brief Set last position to be a new updated one
     *
     */
    void set_last_pos(Position p) { last_pos_ = p; }

private:
    double collision_delta_;
    Position last_pos_;
};