#include "ANIMALS.h"
#include "NetPetShop.h"
#include "Command.h"
#include "CommandNet.h"
#include<iostream>
using namespace std;

void showMenu()
{
	Command cmd;
	Command1 cmd1;

	cout << "PET STORE" << endl;

	animals c;
	NetPetShop c1;
	int maxLen = 50;
	int maxLen1 = 50;
	char* kinds = new char[maxLen],
		* color = new char[maxLen],
		* streets = new char[maxLen],
		* model = new char[maxLen];

	char* name = new char[maxLen1],
		* address = new char[maxLen1];

	while (true)
	{
		cout << "1. Show animals." << endl;
		cout << "2. Add new animals" << endl;
		cout << "3. Get most popular kind" << endl;
		cout << "4. Add pet store" << endl;
		cout << "0 - Exit" << endl;

		char userInput;
		cin >> userInput;

		bool isExit = false;

		switch (userInput)
		{
		case '1':
			cmd.Writeanimals();
			break;
		case '2':
			cout << "Enter animals info:" << endl;
			cout << "Kind>" << endl;
			cin >> kinds;
			cout << "Species>" << endl;
			cin >> model;
			cout << "Color>" << endl;
			cin >> color;
			cout << "Street>" << endl;
			cin >> streets;
			c = animals(kinds, model, color);

			try
			{
				cmd.Addanimals(c);
			}
			catch (const char* err)
			{
				cout << err << endl;
			}
			break;
		case '3':
			cout << "Most popular kind is " << cmd.GetMostPopularAnimalKinds() << endl;
			break;
		case '4':
			cout << "Enter animals shop info:" << endl;
			cout << "Name>" << endl;
			cin >> name;
			cout << "Address>" << endl;
			cin >> address;
			c1 = NetPetShop(name, address);

			try
			{
				cmd1.Addpetshop(c1);
			}
			catch (const char* err)
			{
				cout << err << endl;
			}
			break;

		case '0':
			isExit = true;
			break;
		default:
			break;
		}

		if (isExit)
			break;

		cout << endl << endl;
	}
	delete[]kinds;
	delete[]model;
	delete[]color;
	delete[]streets;
}

int main()
{
	showMenu();
	return 0;
}