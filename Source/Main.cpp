#include "MainInterface.h"//this is where everything connects
#include <iostream>
#include <string>

using namespace std;

uint16_t mainMenu() {
	uint16_t input = 0;//entering string loops QUESTION
	const uint16_t MENU_QUIT = 8;
	Interface interfacemain;//displays different menus accordingly

	while (input != MENU_QUIT)
	{
		input = interfacemain.DisplayMainMenu();

		switch (input)
		{
		case 1:
			system("cls");
			cout << "Sensor smart device" << endl;
			cout << "There are 3 different sensors in this program." << endl;
			cout << "The following sensors are:" << endl;
			cout << "1. Temperature - measures the current temperature and adjustable." << endl;
			cout << "2. Wind - This includes the speed and blades direction that can be modified." << endl;
			cout << "3. Humidity - Takes readings of the humidity percentage." << endl;
			break;
		case 2:
			interfacemain.displaylogin();
			break;
		case 3:
			interfacemain.displaysensors();
			break;
		case 4:
			interfacemain.displaytemp();
			break;
		case 5:
			interfacemain.displaywind();
			break;
		case 6:
			interfacemain.displayhumidity();
			break;
		case 7:
			interfacemain.displayloggedout();
			break;
		case 8:
			break;
		default:
			cout << "Please input a valid option!" << endl;
			cin.clear();
			cin.ignore();
			break;
		}
		cin.clear();//makes sure the input options are cleared just in case it is anything else other than an integer
		cin.ignore();
		system("pause");
	}
	return input;
}

void startup() {
	cout << "Starting system...\n";
	cout << "Initiate users...\n";
	//makes sure all the files exist so the user is aware on startup as to what is loaded and what isn't
	fstream input;
	input.open("login.data");
	if (!input.fail())
	{
		cout << "User login data loaded successfully..." << endl;
	}
	else cout << "User login data did not load!" << endl;
	input.close();

	input.open("general.data");
	if (!input.fail())
	{
		cout << "General sensor data loaded successfully..." << endl;
	}
	else cout << "General sensor data did not load!" << endl;
	input.close();

	input.open("humidity.data");
	if (!input.fail())
	{
		cout << "Humidity sensor data loaded successfully..." << endl;
	}
	else cout << "Humidity sensor data did not load!" << endl;
	input.close();

	input.open("temperature.data");
	if (!input.fail())
	{
		cout << "Temperature sensor data loaded successfully..." << endl;
	}
	else cout << "Temperature sensor data did not load!" << endl;
	input.close();

	input.open("wind.data");
	if (!input.fail())
	{
		cout << "Wind sensor data loaded successfully..." << endl;
	}
	else cout << "Wind sensor data did not load!" << endl;
	input.close();

	cout << "\nSystem startup complete\n";
	system("pause");
}

void main()
{
	startup();
	mainMenu();
	cout << "Thank you, goodbye!! \n";//end screen when exiting message
} // end main