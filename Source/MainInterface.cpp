#include "MainInterface.h"


uint16_t Interface::DisplayMainMenu()
{
	uint16_t input = 0;//entering string loops QUESTION
	system("cls");
	cout << "Welcome to the weather station\n";
	cout << "Main Menu\n";
	cout << "----------------------------------------\n";
	cout << "1: Information about program\n";
	cout << "----------------------------------------\n";

	if (userExist == 0)
	{
		cout << "2: Log in\n";
	}
	else
	{
		cout << "Weather Sensors:\n";
		cout << "3: Overview live feed of all 3 sensors" << endl;
		if (userAuth == 1)//only authorised users gets access to full options
		{
			cout << "4: Temperature\n";
			cout << "5: Wind\n";
			cout << "6: Humidity\n";
		}
		cout << "7: Logout\n";
	}
	cout << "8: Quit\n";

	cout << "Your choice: ";
	cin >> input;
	return input;
}

void Interface::displaylogin()
{
	if (userExist == 0)
	{
		userExist = Logins.check();//checks username and password, returns with 0 for not logged in, 1 for logged in successfully
		if (userExist == 1)
		{
			userAuth = Logins.checkauthorisation();
		}
		else cout << "Not Authorised!" << endl;
	}
	else cout << "You must be logged out to log in!" << endl;
}

void Interface::displaysensors()
{
	if (userExist == 1)
	{
		sensor.display();
	}
	else cout << "You must be logged in to enter this option!" << endl;
}

void Interface::displaytemp()
{
	if (userExist == 1 && userAuth == 1)
	{
		temp.display();
	}
	else cout << "Please login first and make sure to have the correct authorisation level!" << endl;
}

void Interface::displaywind()
{
	if (userExist == 1 && userAuth == 1)
	{
		win.display();
	}
	else cout << "Please login first and make sure to have the correct authorisation level!" << endl;
}

void Interface::displayhumidity()
{
	if (userExist == 1 && userAuth == 1)
	{
		hum.display();
	}
	else cout << "Please login first and make sure to have the correct authorisation level!" << endl;
}

void Interface::displayloggedout()
{
	if (userExist == 1)
	{
		cout << "Logged out!" << endl;
		userExist = 0;//resets the authentication
		userAuth = 0;//resets the authorisation
	}
}