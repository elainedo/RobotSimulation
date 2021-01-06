#ifndef ARENA_PARAMS_H
#define ARENA_PARAMS_H

#include <stdio.h>
#include "arena_entity_params.h"
#include "player_params.h"
#include "../common/position.h"
#include "../common/color.h"

#define MAX_OBSTACLES 8
#define MAX_ROBOTS 8
/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
 /**
 * @brief Define the parameter for the arena.
 *
 * This includes the arena geometry as well as the parameters for \c ALL
 * entities within the arena.
 */
struct arena_params {
  arena_params(void) : obstacles(), n_obstacles(),
                        x_dim(), y_dim() {

    player.battery_max_charge = 100.0;
    player.angle_delta = 10;
    player.collision_delta = 1;
    player.radius = 20.0;
    player.pos = Position(500, 500);
    player.color = Color(0, 0, 255, 255); /* blue */

    obstacles[0].radius = 50.0;
    obstacles[0].pos = Position(800, 200);
    obstacles[0].color = Color(128, 0, 0, 255); /* maroon */

    obstacles[1].radius = 30.0;
    obstacles[1].pos = Position(800, 500);
    obstacles[1].color = Color(75, 0, 130, 255); /* fuchsia */

    obstacles[2].radius = 40.0;
    obstacles[2].pos = Position(300, 500);
    obstacles[2].color = Color(0, 255, 255, 255); /* aqua */

    obstacles[3].radius = 30.0;
    obstacles[3].pos = Position(500, 600);
    obstacles[3].color = Color(255, 255, 0, 255); /* yellow */

    obstacles[4].radius = 30.0;
    obstacles[4].pos = Position(200, 200);
    obstacles[4].color = Color(128, 128, 128, 255); /* grey */

    n_obstacles = 5;
    n_robots = 5;
    x_dim = 1024;
    y_dim = 768;
}

struct player_params player;
struct arena_entity_params obstacles[MAX_OBSTACLES];

size_t n_robots;
size_t n_obstacles;
int x_dim;
int y_dim;

};

#endif