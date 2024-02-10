#include "main.h"
#include "pros/misc.h"

void controlWings()
{
    if(controller.get_digital_new_press(DIGITAL_UP))
    {
        frontLeftWing.set_value(!frontLeftWing.get_value());
        frontRightWing.set_value(!frontRightWing.get_value());
    }
    if(controller.get_digital_new_press(DIGITAL_DOWN))
    {
        backLeftWing.set_value(!backLeftWing.get_value());
        backRightWing.set_value(!backRightWing.get_value());
    }
    if(controller.get_digital_new_press(DIGITAL_B))
    {
        ptoRatchet.set_value(!ptoRatchet.get_value());
    }
}