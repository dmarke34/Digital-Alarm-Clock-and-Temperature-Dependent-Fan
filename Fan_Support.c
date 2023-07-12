#include <p18f4620.h>
#include "Main.h"
#include "Fan_Support.h"
#include "stdio.h"

extern char HEATER;
extern char duty_cycle;
extern char heater_set_temp;
extern signed int DS1621_tempF;

int get_duty_cycle(signed int temp, int set_temp)
{
// add code to check if temp is greater than set_temp. If so, dc = 0. Else dc = 2 times of difference of set_temp and temp
// check if dc is greater than 100. If so, set it to 100
// return dc
    if(temp > set_temp)
    {
        duty_cycle = 0;
    }
    else
    {
        duty_cycle = 2*(set_temp - temp);
    }
    
    if(duty_cycle > 100)
    {
        duty_cycle = 100;
    }
    
    return duty_cycle;
}

void Monitor_Heater()
{
    duty_cycle = get_duty_cycle(DS1621_tempF, heater_set_temp);
    do_update_pwm(duty_cycle);
    if (HEATER == 1) 
    {
        FAN_EN = 1;
        Turn_On_Fan();
    }
    else 
    {
        FAN_EN = 0;
        Turn_Off_Fan();
    }
}

void Toggle_Heater()
{
    if (HEATER == 0)
    {
        HEATER = 1;              // Turn on Fan if toggled and previously off
    }
    else
    {
        HEATER = 0;             // Turn off Fan if toggled and previously on
    }
}

int get_RPM()
{
    int RPS = TMR3L / 2;            // Read the count. Since there are 2 pulses per rev
                                    // then RPS = count/2
    TMR3L = 0;                      // Clear out the count
    return(RPS * 60);               // Return RPM = 60 * RPS
}

void Turn_Off_Fan()
{  
    FAN_LED = 0;                    // Turn off fan LED
}

void Turn_On_Fan()
{
    FAN_LED = 1;  
}







