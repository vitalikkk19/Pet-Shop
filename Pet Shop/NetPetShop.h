#ifndef NetPetShop_H
#define NetPetShop_H

#include<string>
using namespace std;

class NetPetShop
{
	string name;
	string address;

public:
	NetPetShop(string = "", string = "Lviv");
	void Write();

	string GetName();
	string GetAddress();
};

#endif 
