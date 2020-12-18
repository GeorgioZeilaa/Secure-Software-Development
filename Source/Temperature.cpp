#include <Temperature.h>

void Temperature::display(void)
{
	uint16_t input;
	system("cls");
	cout << "----------------------------------------\n";
	cout << "This is the Temperature weather sensor!" << endl;
	cout << "----------------------------------------\n";
	cout << "What would you like to do?" << endl;
	cout << "1. View the current temperature" << endl;
	cout << "2. View the previous temperature readings" << endl;
	cout << "3. Adjust current temperature" << endl;
	cout << "4. Return to main menu" << endl;
	cin >> input;
	switch (input) //different options for different menus
	{
	case 1: temperaturereading();
		break;
	case 2: previoustemperaturereading();
		break;
	case 3: adjusttemperature();
		break;
	case 4://returns to the main menu
		break;
	default:
		cout << "Please input a valid option!" << endl;//if anything else in entered
		cin.clear();
		cin.ignore();
		display();
	}
}

void Temperature::temperaturereading(void)
{
	//for saving temperature reading in file
	ofstream inputfile;

	inputfile.open("temperature.data");
	if (!inputfile)
	{
		cout << "File could not be opened!" << endl;
		display();
	}
	else
	{
		inputfile.clear();//makes sure the old data is not there
		string message;//for the message

		uint16_t integergen;//variable to store the random integer that is generated

		srand(time(NULL));
		integergen = rand() % 10 + 1;//generate a random starting temperature
		uint16_t i = integergen;

		cout << "Current temperature readings: " << endl;
		for (;i < 28; i++)
		{
			uint16_t temp = i;
			if (i < 25)
			{
				cout << "Current Temperature: " << temp << "\370C" << endl;
				Sleep(500);

				inputfile << "Current Temperature: ";
				inputfile << i;
				inputfile << "\370C";
				inputfile << "\n";
			}
		}

		uint16_t randomint;
		uint16_t temp2 = 0;
		srand(time(NULL));
		randomint = rand() % ((5 - 0) + 1) + 0;
		for (uint16_t n = 0; n < 5; n++)
		{
			if (i > 26)
			{
				cout << "The temperature is rising, getting warmer(25+)(ADJUSTING)!" << endl;

				temp2 = i - randomint - n;
				cout << "Current Temperature: " << temp2 << "\370C" << endl;
				Sleep(500);

				inputfile << "The temperature is rising, getting warmer(25+)(ADJUSTING)!";
				inputfile << "\n";
				inputfile << "Current Temperature: ";
				inputfile << temp2;
				inputfile << "\370C";
				inputfile << "\n";
			}
		}
		cout << "Would you like to save the data?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		uint16_t input;
		cin >> input;

		if (input == 2)
		{
			opened = 0;
			inputfile.close();//closs the old file
			inputfile.open("temperature.data");//opens a new file to overwrite the old one
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
void Temperature::previoustemperaturereading(void)
{
	ifstream outputfile;
	outputfile.open("temperature.data");

	if (!outputfile)
	{
		cout << "Could not open file for temperature previous readings!" << endl;
		system("pause");
	}
	else if (opened == 0)
	{
		cout << "EMPTY!\n Make sure to view the current temperature reading and to save the file before trying to view the previous data!" << endl;
		system("pause");
	}
	else
	{
		cout << "This contains the temperature reading that was read by the previous temperature reading option!" << endl;
		string line;
		if (outputfile.is_open())
		{
			cout << outputfile.rdbuf() << endl;
		}
		outputfile.close();
		system("pause");
	}
	display();//returning to the main display of the current sensor
}
void Temperature::adjusttemperature(void)
{
	uint16_t input;
	cout << "What temperature would you like it to be?" << endl;
	cout << "Possible ranges are between 10 - 28" << endl;
	cin >> input;

	if (input >= 10 && input <= 28)
	{
		cout << "You chosen temperature: " << input <<"\370C"<< endl;
		uint16_t integergen;//variable to show the random integer that is generated

		srand(time(NULL));
		integergen = rand() % 10 + 1;//generate a random starting temperature

		cout << "Current temperature reading: " << integergen << "\370C" << endl;
		while (input != integergen)
		{
			cout << "Adjusting current temperature!" << endl;
			integergen = input;
		}
		if (input == integergen)
		{
			cout << "Temperature adjusted!" << endl;
			cout << "Current temperature: " << input << "\370C" << endl;
		}
	}
	else cout << "Input only within the limits provided!" << endl;

	cin.clear();
	cin.ignore();
	system("pause");
	display();
}