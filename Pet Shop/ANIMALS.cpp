#include "ANIMALS.h"
#include <iostream>

using namespace std;

animals::animals(string kinds, string model, string color, int amount,
	int pricee, string streets)
{
	this->kinds = kinds;
	this->model = model;
	this->color = color;
	this->amount = amount;
	this->pricee = pricee;
	this->streets = streets;
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
