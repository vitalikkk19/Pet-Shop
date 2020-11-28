#ifndef COMMANDNET_H
#define COMMANDNET_H

#include"NetPetShop.h"

class Command1
{
	NetPetShop* NetPetShopp;
	int lastPetIndex;

public:
	Command1();
	~Command1();

	void Addpetshop(NetPetShop&);
	void Writepetshop();
};

#endif 