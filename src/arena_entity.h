#include <iostream>
#include <string>
#include "position.h"
#include "color.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A base class representing an entity within the arena. All entities
 * within the arena
 *
 * 1. Update themselves each timestep (i.e. in accordance with current velocity
 *    and position).
 *
 * 2. Reset themselves to a newly constructed state. This is so the user can
 *    click the reset button after completing a game and have things work as
 *    expected.
 *
 * Please note that here use the upper-left coordinate, which means that the
 * origin point (0.0,0.0) is at the upper left.
 *
 * Also, all arena entities are circular.
 */
class ArenaEntity {
    public:
    ArenaEntity(double radius, const Position& pos,
                const Color& color) :
        radius_(radius), pos_(pos), color_(color) {}
    virtual ~ArenaEntity(void) {}

    /**
     * @brief Perform whatever updates are needed for a particular entity after 1
     * timestep (updating position, changing color, etc.).
     */
    virtual void TimestepUpdate(__unused uint dt) {}

    /**
     * @brief Reset the entity to its newly constructed state.
     */
    virtual void Reset(void) {}

    /**
     * @brief Get the name of an entity for visualization purposes, to aid in
     * debugging.
     */
    virtual std::string get_name(void) const = 0;

    /**
     * @brief Set position of the entity
     */
    void set_pos(const Position& pos) { pos_ = pos; }

    /**
     * @brief Get position of the entity
     */
    const Position& get_pos(void) const { return pos_; }

    /**
     * @brief Get color of the entity
     */
    const Color& get_color(void) const { return color_; }

    /**
     * @brief Set color of the entity
     */
    void set_color(const Color& color) { color_ = color; }

    /**
     * @brief Get radius of the entity
     */
    double radius(void) const { return radius_; }

private:
    double radius_;
    Position pos_;
    Color color_;
};