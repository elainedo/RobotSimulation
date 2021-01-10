
#ifndef EVENT_KEYPRESS_H_
#define EVENT_KEYPRESS_H_

#include <stdio.h>
#include "event_base_class.h"
#include "../motion_handlers/motion_commands.h"

class EventKeypress : public EventBaseClass {
public:
    explicit EventKeypress(int key) : key_(key) {}

    void EmitMessage(void) override { printf("Keypress command received\n"); }

    enum motion_commands keypress_to_cmd(int key) const;

    enum motion_commands get_cmd() const;

    enum event_types get_type() const override { return kEventKeypress; }

private:
    int key_;
};

#endif 