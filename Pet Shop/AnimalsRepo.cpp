#include"AnimalsRepo.h"
#include<fstream>
#include<iostream>

using namespace std;

AnimalsRepo::AnimalsRepo(bool sync) :Repository(sync)
{
	ReadFromStorage();
}

AnimalsRepo::~AnimalsRepo(){}

void AnimalsRepo::Show()
{
	for (int i = 0; i <= current; i++) {
		cout << i + 1 << endl;
		((animals*)data[i])->Write();
	}
}