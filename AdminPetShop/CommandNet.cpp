#include "CommandNet.h"
#include "NetPetShop.h"
#include <iostream>
#include <fstream>
using namespace std;

Command1::Command1()
{
	NetPetShopp = new NetPetShop[100];
	lastPetIndex = -1;

	ifstream fin1("NetPetShop.txt");

	int maxlen1 = 50;
	char* name = new char[maxlen1],
		* address = new char[maxlen1];
	char delim1 = ',';
	while (!fin1.eof())
	{
		fin1.get(name, maxlen1, delim1);
		fin1.get();
		fin1.get(address, maxlen1);

		NetPetShop NetPetShop(name, address);
		Addpetshop(NetPetShop);
	}

	fin1.close();
	delete[] name;
	delete[] address;
}

Command1::~Command1()
{
	ofstream fout1("NetPetShop.txt");

	for (int i = 0; i <= lastPetIndex; i++)
	{
		fout1 << NetPetShopp[i].GetName() << ","
			<< NetPetShopp[i].GetAddress();

		if (i < lastPetIndex)
			fout1 << endl;
	}

	fout1.close();

	delete[] NetPetShopp;
}

void Command1::Addpetshop(NetPetShop& NetPetShop)
{
	if (lastPetIndex >= 100)
	{
		throw "no memory for pet shop!!!";
	}

	NetPetShopp[++lastPetIndex] = NetPetShop;
}

void Command1::Writepetshop()
{
	cout << "Added pet shop:" << endl;
	for (int i = 0; i <= lastPetIndex; i++)
	{
		NetPetShopp[i].Write();
	}
}