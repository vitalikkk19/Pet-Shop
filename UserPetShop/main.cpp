#include "ANIMALS.h"
#include "NetPetShop.h"
#include "Command.h"
//#include"Command.cpp"
#include<iostream>
using namespace std;

void showMenu()
{
	Command cmd;

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
		cout << "2. Get most popular kind" << endl;
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
			cout << "Most popular kind is " << cmd.GetMostPopularAnimalKinds() << endl;
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