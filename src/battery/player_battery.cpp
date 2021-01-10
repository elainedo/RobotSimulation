/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "player_battery.h"
#include <math.h>
#include <cmath>

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double PlayerBattery::Deplete(__unused Position old_pos,
  __unused Position new_pos, __unused double dt) {
    double linear_dis = sqrt(pow((new_pos.x() - old_pos.x()), 2) +
        pow((new_pos.y() - old_pos.y()), 2));
    if (linear_dis == 0) {
        return charge_;
    }
    double linear_vel = linear_dis/dt;
    charge_ = charge_ - kBASE_DEPLETION - (linear_vel*kLINEAR_SCALE_FACTOR);
    if (charge_ < 0) charge_ = 0;
    return charge_;
} /* deplete() */

double PlayerBattery::UpdateBatteryLevel(SensorTouch sensor_touch,
    __unused Position old_pos, __unused Position new_pos, __unused double dt) {
    Deplete(old_pos, new_pos, dt);
    if (sensor_touch.activated()) {
        if (sensor_touch.get_entity_type() == kRechargeStation) {
        EventRecharge();
        }
    }
    return charge_;
}

void PlayerBattery::Accept(__unused const EventCollision * const e) {
    /* @todo deplete battery by some value -- arbitrary selected for bumping */
    if (e->collided()) {
        charge_ = charge_ - 5;
        if (charge_ < 0) charge_ = 0;
    }
}