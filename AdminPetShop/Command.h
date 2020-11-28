#ifndef COMMAND_H
#define COMMAND_H

#include"ANIMALS.h"

class Command
{
	animals* animalss;
	int lastAnimalsIndex;

public:
	Command();
	~Command();

	void Addanimals(animals&);
	void Writeanimals();
	string GetMostPopularAnimalKinds();

};

#endif 