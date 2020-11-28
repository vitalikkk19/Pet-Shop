#ifndef ANIMALS_H
#define ANIMALS_H

#include<string>
using namespace std;

class animals
{
	string kinds;
	string model;
	string color;
	int amount;
	int pricee;
	string streets;

public:
	animals(string = "", string = "", string = "", int = 2,
		int = 100, string = "");

	void Write();


	string Getkinds();
	string GetModel();
	string GetColor();
	int Getamount();
	int Getpricee();
	string GetEngineCapacity();
};

#endif 