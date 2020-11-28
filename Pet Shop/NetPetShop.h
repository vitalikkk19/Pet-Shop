#ifndef NetPetShop_H
#define NetPetShop_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class NetPetShop
{
	string name;
	string address;

public:
	NetPetShop(string = "", string = "Lviv");
	virtual void Write();

	string GetName();
	string GetAddress();
	string GetStorageName();
	friend ifstream& operator>>(ifstream& fin, NetPetShop& NetPetShopp);
	friend ofstream& operator<<(ofstream& fout, NetPetShop& NetPetShopp);
	friend ostream& operator<<(ostream& out, NetPetShop& NetPetShopp);
};

#endif 
