#ifndef HUMIDITY_H
#define HUMIDITY_H

#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

class Humidity
{
private:
	uint16_t opened = 0;
public:
	void display(void);
	void humidityreading(void);
	void previoushumidityreading(void);
	void adjusthumidity(void);
};

#endif