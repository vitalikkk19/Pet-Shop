#include "ANIMALS.h"
#include <iostream>

using namespace std;

animals::animals(string kinds, string model, string color, int amount,
	int pricee, string streets, float engineCapacity)
{
	this->kinds = kinds;
	this->model = model;
	this->color = color;
	this->amount = amount;
	this->pricee = pricee;
	this->streets = streets;
	this->engineCapacity = engineCapacity;
}

void animals::Write()
{
	cout << "Animals info: " << kinds << "; " << model << "; " << color << "; " << amount << "; " << pricee << "; " << streets << endl;
}

string animals::Getkinds()
{
	return kinds;
}

string animals::GetModel()
{
	return model;
}

int animals::Getamount()
{
	return amount;
}

string animals::GetColor()
{
	return color;
}

int animals::Getpricee()
{
	return pricee;
}

string animals::GetEngineCapacity()
{
	return streets;
}
//////////////////////////////////////////////////////////////////////
string animals::GetStorageName()
{
	return "ANIMALS.txt";
}

string animals::GetHeader()
{
	return "Animals info:";
}

ifstream& operator>>(ifstream& fin, animals& animals)
{
	int maxLen = 50;
	char* kinds = new char[maxLen],
		* model = new char[maxLen],
		* color = new char[maxLen],
		* amount = new char[maxLen],
		* pricee = new char[maxLen],
		* streets = new char[maxLen];
	char* engineCapacity = new char[maxLen];

	char delim = ',';

	fin.get(kinds, maxLen, delim);
	fin.get();
	fin.get(model, maxLen, delim);
	fin.get();
	fin.get(color, maxLen, delim);
	fin.get();
	fin.get(amount, maxLen, delim);
	fin.get();
	fin.get(pricee, maxLen, delim);
	fin.get();
	fin.getline(streets, maxLen);
	fin.get();
	fin.getline(engineCapacity, maxLen);

	animals.kinds = kinds;
	animals.model = model;
	animals.color = color;
	animals.amount = atoi(amount);
	animals.pricee = atoi(pricee);
	animals.streets = streets;

	delete[] kinds;
	delete[] model;
	delete[] amount;
	delete[] color;
	delete[] pricee;
	delete[] streets;

	return fin;
}

ofstream& operator<<(ofstream& fout, animals& animals)
{
	fout << animals.kinds << ","
		<< animals.model << ","
		<< animals.amount << ","
		<< animals.color << ","
		<< animals.pricee << ","
		<< animals.streets << ","
		<< animals.engineCapacity;
	return fout;
}


ostream& operator<<(ostream& out, animals& animals)
{
	string delim = ",";
	out << animals.kinds << delim
		<< animals.model << delim
		<< animals.amount << delim
		<< animals.color << delim
		<< animals.pricee << delim
		<< animals.streets << delim
		<< animals.engineCapacity;
	return out;
}