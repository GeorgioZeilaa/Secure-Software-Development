#ifndef WIND_H
#define WIND_H

#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

class Wind
{
private:
	uint16_t opened = 0;
public:
	void display(void);
	void windreading(void);
	void previouswindreading(void);
	void adjustwind(void);
	string windstate = "Neutral";
};

#endif