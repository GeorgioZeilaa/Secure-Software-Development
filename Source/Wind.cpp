#include <Wind.h>

void Wind::display(void)
{
	uint16_t input;
	system("cls");
	cout << "----------------------------------------\n";
	cout << "This is the Wind weather sensor!" << endl;
	cout << "----------------------------------------\n";
	cout << "What would you like to do?" << endl;
	cout << "1. View the current wind readings" << endl;
	cout << "2. View the previous wind readings" << endl;
	cout << "3. Adjust wind blades" << endl;
	cout << "4. Return to main menu" << endl;
	cin >> input;
	switch (input) //different options for different menus
	{
	case 1: windreading();
		break;
	case 2: previouswindreading();
		break;
	case 3: adjustwind();
		break;
	case 4://returns to the main menu
		break;
	default:
		cout << "Please input a valid option!" << endl;//if anything else in entered
		cin.clear();
		cin.ignore();
		display();
		break;
	}
}

void Wind::windreading(void)
{
	ofstream inputfile;
	inputfile.open("wind.data");
	if (inputfile.fail())
	{
		cout << "Could not open the wind statistics file!" << endl;
		display();
	}
	else
	{
		uint16_t integergen;//variable to show the random integer that is generated

		srand(time(NULL));
		integergen = rand() % 10 + 1;//generate a random starting wind speed

		cout << "Current wind statistic: " << endl;
		for (uint16_t i = integergen; i < 25; i++)
		{
			Sleep(500);

			inputfile.clear();

			string n = "North";
			cout << "Wind Speed: " << i << " mph" << endl;

			if (i >= 0 && i <= 5)
			{
				n = "North";
			}
			if (i >= 6 && i <= 10)
			{
				n = "North-East";
			}
			if (i >= 11 && i <= 16)
			{
				n = "South-East";
			}
			if (i >= 17 && i <= 20)
			{
				n = "East";
			}
			if (i >= 21 && i < 25)
			{
				n = "West";
			}
			cout << "Direction: " << n << endl;
			inputfile << "Wind speed: ";
			inputfile << i;
			inputfile << " mph\n";
			inputfile << "Direction: ";
			inputfile << n;
			inputfile << "\n";
		}
		cout << "Would you like to save the data?(this will overwrite the previous data)" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		uint16_t input;
		cin >> input;

		if (input == 2)
		{
			opened = 0;
			inputfile.close();//closs the old file
			inputfile.open("wind.data");//opens a new file to overwrite the old one
		}
		if (input == 1)
		{
			opened = 1;
		}
		inputfile.close();
	}
	display();
}
void Wind::previouswindreading(void)
{
	ifstream outputfile;
	outputfile.open("wind.data");

	if (!outputfile)//checks if the file exist
	{
		cout << "Could not open wind statistics!" << endl;
		system("pause");
	}
	else if (opened == 0)
	{
		cout << "EMPTY FILE! \n make sure to run the wind statistics option 1 first before trying to view the previous ones!" << endl;
		system("pause");
	}
	else
	{
		if (outputfile.is_open())
		{
			cout << outputfile.rdbuf() << endl;
		}
		outputfile.close();
		system("pause");
	}
	display();//returning to the main display of the current sensor
}

void Wind::adjustwind(void)
{
	uint16_t input;

	cout << "Adjusting the blades" << endl;
	cout << "-------------------" << endl;
	cout << "Current wind blades state" << windstate << endl;
	cout << "What wind blades state would you like it to be?" << endl;
	cout << "1. Neutral" << endl;
	cout << "2. 50% open" << endl;
	cout << "3. 100% open" << endl;
	cout << "4. 0%, fully closed" << endl;

	cin >> input;
	switch (input) //different options for different menus
	{
	case 1:
		if (windstate == "Neutral")//checks if the state is already set
		{
			cout << "WARNING! The blades state is already in the state of " << windstate << endl;
			system("pause");
		}
		else
		{
			uint16_t integergen;//variable to show the random integer that is generated

			srand(time(NULL));
			integergen = rand() % 10 + 1;//generate a random starting wind speed

			cout << "Current wind statistic: " << endl;
			for (uint16_t i = integergen; i < 25; i++)
			{
				Sleep(500);
				cout << "Wind Speed: " << i << " mph" << endl;
				cout << "Adjusting the blades" << endl;
				if (i >= 0 && i <= 10)
				{
					windstate = "100% open";
				}
				if (i >= 11 && i <= 16)
				{
					windstate = "50% open";
				}
				if (i >= 17 && i <= 25)
				{
					windstate = "Neutral";
				}
				cout << "Blades State: " << windstate << endl;
			}
			cout << "Successfully changed the state!" << endl;
			system("pause");
		}
		display();
		break;
	case 2: 
		if (windstate == "50% open")
		{
			cout << "WARNING! The blades state is already in " << windstate << endl;
			system("pause");
		}
		else 
		{
			uint16_t integergen;//variable to show the random integer that is generated

			srand(time(NULL));
			integergen = rand() % 10 + 1;//generate a random starting wind speed

			cout << "Current wind statistic: " << endl;
			for (uint16_t i = integergen; i < 17; i++)
			{
				Sleep(500);
				cout << "Wind Speed: " << i << " mph" << endl;
				cout << "Adjusting the blades" << endl;
				if (i >= 0 && i <= 10)
				{
					windstate = "100% open";
				}
				if (i >= 11 && i <= 16)
				{
					windstate = "50% open";
				}
				cout << "Blades State: " << windstate << endl;
			}
			cout << "Successfully changed the state!" << endl;
			system("pause");
		}
		display();
		break;
	case 3:
		if (windstate == "100% open")
		{
			cout << "WARNING! The blades state is already in " << windstate << endl;
			system("pause");
		}
		else
		{
			uint16_t integergen;//variable to show the random integer that is generated

			srand(time(NULL));
			integergen = rand() % 10 + 1;//generate a random starting wind speed

			cout << "Current wind statistic: " << endl;
			for (uint16_t i = integergen; i < 11; i++)
			{
				Sleep(500);
				cout << "Wind Speed: " << i << " mph" << endl;
				cout << "Adjusting the blades" << endl;
				if (i >= 0 && i <= 10)
				{
					windstate = "100% open";
				}
				cout << "Blades State: " << windstate << endl;
			}
			cout << "Successfully changed the state!" << endl;
			system("pause");
		}
		display();
		break;
	case 4:
		if (windstate == "0%, fully closed")
		{
			cout << "WARNING! The blades state is already in " << windstate << endl;
			system("pause");
		}
		else
		{
			uint16_t integergen;//variable to show the random integer that is generated

			srand(time(NULL));
			integergen = rand() % 10 + 1;//generate a random starting wind speed

			cout << "Current wind statistic: " << endl;
			for (uint16_t i = integergen; i < 3; i++)
			{
				Sleep(500);
				cout << "Wind Speed: " << i << " mph" << endl;
				cout << "Adjusting the blades" << endl;

				windstate = "0%, fully closed";

				cout << "Blades State: " << windstate << endl;
			}
			cout << "Successfully changed the state!" << endl;
			system("pause");
		}
		display();
		break;
	default:
		cout << "Please input a valid option!" << endl;//if anything else in entered
		cin.clear();
		cin.ignore();
		display();
		break;
	}
}