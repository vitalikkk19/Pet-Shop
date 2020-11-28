#include "NetPetShop.h"
#include <iostream>
using namespace std;

NetPetShop::NetPetShop(string name, string address)
{
	this->name = name;
	this->address = address;
}

void NetPetShop::Write()
{
	cout << "Pet shop info: " << name << " " << address << endl;
}

string NetPetShop::GetName()
{
	return name;
}

string NetPetShop::GetAddress()
{
	return address;
}
