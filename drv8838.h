// drv8838.h
// Basic Arduino library for the TI DRV8838 motor driver
// Christopher Green - Use this code at your own risk/peril

#define FORWARD 0
#define BACKWARD 1

#ifndef drv8838_h
#define drv8838_h

#include "Arduino.h"

class drv8838{
public:
	drv8838(); //default constructor
	drv8838(uint8_t, uint8_t); //constructor that sets pins for board - enable, phase - enable should be PWM
	void configure(uint8_t, uint8_t); //manually sets pins for board - enable, phase - enable should be PWM
	void setDirection(bool); //set motor direction
	void setSpeed(uint8_t); //set motor speeds
private:
	bool _check_valid(); //check that configuration is set before doing anything
	uint8_t _EN_pin, _PH_pin; //enable and phase pins
};

#endif
