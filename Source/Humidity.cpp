#include "Humidity.h"

void Humidity::display()
{
	uint16_t input;
	system("cls");
	cout << "----------------------------------------\n";
	cout << "This is the Humidity weather sensor!" << endl;
	cout << "----------------------------------------\n";
	cout << "What would you like to do?" << endl;
	cout << "1. View the current humidity percentage" << endl;
	cout << "2. View the previous humidity percentage" << endl;
	cout << "3. Adjust the humidity level" << endl;
	cout << "4. Return to main menu" << endl;
	cin >> input;
	switch (input) //different options for different menus
	{
	case 1: humidityreading();
		break;
	case 2: previoushumidityreading();
		break;
	case 3: adjusthumidity();
		break;
	case 4://returns to the main menu
		break;
	default:
		cout << "Please input a valid option!" << endl;//if anything else in entered
		display();
	}
}

void Humidity::humidityreading()
{
	//for saving humidity reading in file
	ofstream inputfile;

	inputfile.open("humidity.data");
	if (!inputfile)
	{
		cout << "File could not be opened!" << endl;
		display();
	}
	else
	{
		inputfile.clear();

		uint16_t integergen;//variable to store the random integer that is generated

		srand(time(NULL));
		integergen = rand() % 10 + 1;//generate a random starting humidity

		cout << "Current temperature reading: " << endl;
		for (uint16_t i = integergen; i < 95; i++)
		{
			i = i + 5;
			cout << "Current Humidity percentage: " << i << "%" << endl;
			Sleep(500);
			//saving to file which is the same that was outputted out screen
			inputfile << "Current Humidity percentage: ";
			inputfile << i;
			inputfile << "%";
			inputfile << "\n";

			if (i > 50)//if humidity level goes above 50% then a warning message will appear and save in file
			{
				inputfile << "WARNING! The humidity is rising, getting humid(50+)! \n ";
				cout << "WARNING! The humidity is rising, getting humid(50+)!" << endl;
			}
		}
		cout << "Would you like to save the data?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		uint16_t input;
		cin >> input;

		if (input == 2)
		{
			opened = 0;//a variable to keep up if the file has existing data or is empty
			inputfile.close();//closes the old file
			inputfile.open("humidity.data");//opens a new file to overwrite the old one
		}
		if (input == 1)
		{
			opened = 1;
		}

		inputfile.close();//closes the overwrite file that we just opened
		system("pause");
		display();
	}
}

void Humidity::previoushumidityreading()
{
	ifstream outputfile;//for reading humidity.data file
	outputfile.open("humidity.data");

	if (!outputfile)
	{
		cout << "Could not open file for humidity previous readings!" << endl;
		system("pause");
	}
	else if (opened == 0)//if it was not written to before then this message will appear
	{
		cout << "EMPTY!\n Make sure to view the current humidity reading and to save the file before trying to view the previous data!" << endl;
		system("pause");
	}
	else
	{
		cout << "This contains the humidity reading that was read by the previous humidity reading option!" << endl;

		if (outputfile.is_open())
		{
			cout << outputfile.rdbuf() << endl;
		}
		outputfile.close();
		system("pause");
	}
	display();//returning to the main display of the current sensor
}

void Humidity::adjusthumidity()
{
	uint16_t input;
	cout << "WARNING! This will set the humidity level as close as you wish, not 100% accurate!" << endl;
	cout << "What humidity level would you like it to be?" << endl;
	cout << "Enter 1, 2 or 3:" << endl;
	cout << "1. 25%" << endl;
	cout << "2. 50%" << endl;
	cout << "3. 75%" << endl;
	cin >> input;

	if (input == 1)
	{
		input = 25;
	}
	if (input == 2)
	{
		input = 50;
	}
	if (input == 3)
	{
		input = 75;
	}

	uint16_t integergen;//variable to show the random integer that is generated

	srand(time(NULL));
	integergen = rand() % 10 + 1;//generate a random starting humidity

	cout << "Current percentage: " << integergen <<"%"<< endl;
	cout << "Adjusting..." << endl;

	for (uint16_t i = integergen; i <= input; i++)
	{
		Sleep(500);
		i = i + 5;
		cout << "Current perentage: " << i << "%" << endl;
	}

	cout << "Humidity level has been adjusted to your option" << endl;

	system("pause");
	display();
}