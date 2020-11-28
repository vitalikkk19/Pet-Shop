#include "Command.h"
#include "ANIMALS.h"
#include <iostream>
#include <fstream>
using namespace std;

Command::Command()
{
	animalss = new animals[100];
	lastAnimalsIndex = -1;

	ifstream fin("ANIMALS.txt");

	int maxLen = 50;
	char* kinds = new char[maxLen],
		* model = new char[maxLen],
		* color = new char[maxLen],
		* amount = new char[maxLen],
		* maxSpeed = new char[maxLen],
		* streets = new char[maxLen];

	char delim = ',';
	while (!fin.eof())
	{
		fin.get(kinds, maxLen, delim);
		fin.get();
		fin.get(model, maxLen, delim);
		fin.get();
		fin.get(color, maxLen, delim);
		fin.get();
		fin.get(amount, maxLen, delim);
		fin.get();
		fin.get(maxSpeed, maxLen, delim);
		fin.get();
		fin.getline(streets, maxLen);

		animals animals(kinds, model, color, atoi(amount), atoi(maxSpeed), streets);
		Addanimals(animals);
	}

	fin.close();

	delete[] kinds;
	delete[] model;
	delete[] amount;
	delete[] color;
	delete[] maxSpeed;
	delete[] streets;

}

Command::~Command()
{
	ofstream fout("ANIMALS.txt");

	for (int i = 0; i <= lastAnimalsIndex; i++)
	{
		fout << animalss[i].Getkinds() << ","
			<< animalss[i].GetModel() << ","
			<< animalss[i].GetColor() << ","
			<< animalss[i].Getamount() << ","
			<< animalss[i].Getpricee() << ","
			<< animalss[i].GetEngineCapacity();

		if (i < lastAnimalsIndex)
			fout << endl;
	}

	fout.close();

	delete[] animalss;
}

void Command::Addanimals(animals& animals)
{
	if (lastAnimalsIndex >= 100)
	{
		throw "no memory for animals!!!";
	}

	animalss[++lastAnimalsIndex] = animals;
}


void Command::Writeanimals()
{
	cout << "Added animals:" << endl;
	for (int i = 0; i <= lastAnimalsIndex; i++)
	{
		animalss[i].Write();
	}
}

string Command::GetMostPopularAnimalKinds()
{
	int maxNrkinds = -1;
	string maxkinds = "";

	for (int i = 0; i <= lastAnimalsIndex; i++)
	{
		int nrOfMakes = 0;
		for (int j = i + 1; j <= lastAnimalsIndex; j++)
		{
			if (animalss[i].Getkinds() == animalss[j].Getkinds())
				nrOfMakes++;
		}
		if (nrOfMakes > maxNrkinds)
		{
			maxNrkinds = nrOfMakes;
			maxkinds = animalss[i].Getkinds();
		}
	}

	return maxkinds;
}