#include <cmath>
#include <iostream>
#include <vector>
#include "../params/arena_params.h"
#include "../events/event_key_press.h"

struct arena_params;

class Arena {
public:
    explicit Arena(const struct arena_params * const params);
    ~Arena(void);

    /**
     * @brief Advance the simulation by the specified # of steps.
     *
     * @param[in] dt The # of steps to increment by.
     */
    void AdvanceTime(double dt);

    /**
     * @brief Handle the key press passed along by the viewer.
     *
     * @param[in] an event holding the key press.
     *
     */
    void Accept(const EventKeypress * const e);

    /**
     * @brief Reset all entities in the arena, effectively restarting the game.
     */
    void Reset(void);

    /*
    * @brief Get # of obstacles in the arena.
    */
    unsigned int n_obstacles(void) { return n_obstacles_; }

    /**
     * @brief Get a list of all obstacles (i.e. non-mobile entities in the arena).
     */
    std::vector<class Obstacle*> obstacles(void);

    /**
     * @brief Get the player in the arena.
     */
    class Player* player(void) const { return player_; }

    /**
     * @brief Get the state of the game if winning
     */
    bool win (void) { return win_; }

    /**
     * @brief Get the state of the game if losing
     */
    bool lose (void) { return lose_; }

private:
  
    // Under certain circumstance, the compiler requires that the copy
    // constructor is not defined. This is deleting the default copy const.
    Arena& operator=(const Arena& other) = delete;
    Arena(const Arena& other) = delete;

    // Dimensions of graphics window inside which robots must operate
    double x_dim_;
    double y_dim_;
    unsigned int n_robots_;
    unsigned int n_obstacles_;

    // Entities
    Player* player_;
    std::vector<class ArenaEntity*> entities_;
    std::vector<class ArenaMobileEntity*> mobile_entities_;

    // win_ and lose_ variables indicate the situation when robot hits HomeBase
    // runs out of battery
    bool win_ = false;
    bool lose_ = false;
};
