// drv8838.cpp
// Basic Arduino library for the TI DRV8838 motor driver
// Christopher Green - Use this code at your own risk/peril

#include drv8838.h

//drv8838:drv8838(); //default constructor

drv8838:drv8838(uint8_t ENABLE, uint8_t PHASE){ //Constructor that sets pins for board - enable should be PWM
	_EN_pin = ENABLE;
	_PH_pin = PHASE;
	pinMode(_EN_pin, OUTPUT);
	pinMode(_PH_pin, OUTPUT);
}

void drv8838:configure(uint8_t ENABLE, uint8_t PHASE){ //Manually set pin values
	_EN_pin = ENABLE;
	_PH_pin = PHASE;
	pinMode(_EN_pin, OUTPUT);
	pinMode(_PH_pin, OUTPUT);
}

void setDirection(bool direction){ //set motor direction
	if(_check_valid())
		digitalWrite(_PH_pin, direction);
}

void setSpeed(uint8_t speed){ //set motor speed (0-255)
	if(_check_valid())
		analogWrite(_EN_pin, speed);
}

bool _check_valid(){ //check that configuration is set before doing anything
	return (_EN_pin && _PH_pin);
}