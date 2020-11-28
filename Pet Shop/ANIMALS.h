#ifndef ANIMALS_H
#define ANIMALS_H

#include<string>
#include<fstream>
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
	float engineCapacity;

public:
	animals(string = "", string = "", string = "", int = 2,
		int = 100, string = "", float = 2);

	void Write();

	string GetStorageName();
	string GetHeader();

	string Getkinds();
	string GetModel();
	string GetColor();
	int Getamount();
	int Getpricee();
	string GetEngineCapacity();

	friend ifstream& operator>>(ifstream& fin, animals& animals);
	friend ofstream& operator<<(ofstream& fout, animals& animals);
	friend ostream& operator<<(ostream& out, animals& animals);
};

#endif 