#include "main.h"

void setIntake(int power)
{
    intake = power;
}

void controlIntake()
{
    if(controller.get_digital(DIGITAL_R1))
    {
        setIntake(127); // 127 max
    }
    else if(controller.get_digital(DIGITAL_R2))
    {
        setIntake(-127);
    }
    else
    {
        setIntake(0);
    }

}