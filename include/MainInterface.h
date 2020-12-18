#ifndef MAIN_INTERFACE_H
#define MAIN_INTERFACE_H

#include <iostream>
#include "Login.h"
#include "Sensors.h"
#include "Temperature.h"
#include "Wind.h"
#include "Humidity.h"

using namespace std;

class Interface
{
private: 
	Login Logins;
	Sensors sensor;
	Temperature temp;
	Wind win;
	Humidity hum;
	unsigned userExist = 0;
	unsigned userAuth = 0;
public:
	uint16_t DisplayMainMenu();
	void displaylogin();
	void displaysensors();
	void displaytemp();
	void displaywind();
	void displayhumidity();
	void displayloggedout();
};

#endif