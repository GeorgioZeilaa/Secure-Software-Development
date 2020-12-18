#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <string>
#include <ctime>  

using namespace std;

class Temperature
{
private:
	uint16_t opened = 0;
public:
	void display(void);
	void temperaturereading(void);
	void previoustemperaturereading(void);
	void adjusttemperature(void);
};

#endif