#include "Sensors.h"

void Sensors::display()
{
	ofstream inputfile;
	inputfile.open("general.data");
	if (inputfile.fail())
	{
		cout << "Could not open the general statistics file!" << endl;
		system("pause");
	}
	else
	{
		cout << "Gathering data!" << endl;
		cout << "\tTemperature\t|\t" << "\tWind\t\t|\t" << "\tHumidity\t|\t" << endl;
		inputfile << "\tTemperature\t|\t" << "\tWind\t\t|\t" << "\tHumidity\t|\t" << endl;
		cout << "\t\t\t|\t\t\t\t|\t\t\t\t|\t" << endl;
		inputfile << "\t\t\t|\t\t\t\t|\t\t\t\t|\t" << endl;
		for (uint16_t i = 0; i < 20; i++)
		{
			uint16_t temperature = 0;
			uint16_t wind = 0;
			uint16_t humidity = 0;
			uint16_t integergen;//variable to show the random integer that is generated

			srand(time(NULL));
			integergen = rand() % 10 + 1;//generate a random starting wind speed

			temperature = integergen + (i);
			wind = integergen + (10 + i);
			humidity = integergen + (i + 40);
			Sleep(500);
			if (temperature >= 25)//temperature gets higher than 25 then a warning it is getting too hot will show up as a message
			{
				cout << temperature << "\370" << "C WARNING(25+)\t|\t";
				inputfile << temperature << "\370" << "C WARNING(25+)\t|\t";
			}
			else
			{
				cout << temperature << "\370" << "C\t\t\t|\t";
				inputfile << temperature << "\370" << "C\t\t\t|\t";
			}
			if (wind >= 30)
			{
				cout << wind << " mph (HIGH WIND)\t|\t";
				inputfile << wind << " mph (HIGH WIND)\t|\t";
			}
			else
			{
				cout << wind << " mph\t\t\t|\t";
				inputfile << wind << " mph\t\t\t|\t";
			}
			if (humidity >= 50)
			{
				cout << humidity << "% (HIGH HUMIDITY)\t|\t" << endl;
				inputfile << humidity << "% (HIGH HUMIDITY)\t|\t" << endl;
			}
			else
			{
				cout << humidity << "%\t\t\t|\t" << endl;
				inputfile << humidity << "%\t\t\t|\t" << endl;
			}
		}
	}
	cout << "Would you like to save the data? (this will overwrite the previous data)" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	uint16_t input;
	cin >> input;

	if (input == 2)
	{
		inputfile.close();//close the old file
		inputfile.open("general.data");//opens a new file to overwrite the old one
	}

	inputfile.close();//closes the file for security purposes
}