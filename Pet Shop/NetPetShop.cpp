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

string NetPetShop::GetStorageName() {
	return "NetPetShop.txt";
}
ifstream& operator>>(ifstream& fin, NetPetShop& NetPetShopp) {
	int maxLen = 50;
	char* name = new char[maxLen],
		* address = new char[maxLen];
	fin.get(name, maxLen);
	fin.get();
	fin.get(address, maxLen);
	NetPetShopp.name = name;
	NetPetShopp.address = address;


	delete[] name;
	delete[] address;
	return fin;
}
ofstream& operator<<(ofstream& fout, NetPetShop& NetPetShopp) {

	fout << NetPetShopp.GetName() << ","
		<< NetPetShopp.GetAddress();
	return fout;
}
ostream& operator<<(ostream& out, NetPetShop& NetPetShopp) {
	string delim = ",";
	out << NetPetShopp.GetName() << delim
		<< NetPetShopp.GetAddress();
	return out;
}