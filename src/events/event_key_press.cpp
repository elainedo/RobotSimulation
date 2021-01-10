/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "event_key_press.h"

enum motion_commands EventKeypress::keypress_to_cmd(int key) const {
    switch (key) {
        case 263:
            return kTurnLeft;
            break;
        case 262:
            return kTurnRight;
            break;
        case 265:
            return kSpeedUp;
            break;
        case 264:
            return kSlowDown;
            break;
        default:
            printf("Unknown keypress: %d\n", key);
            return kInvalid;
    } /* switch() */
} /* keypress_to_cmd() */

enum motion_commands EventKeypress::get_cmd() const {
  return keypress_to_cmd(key_);
}
