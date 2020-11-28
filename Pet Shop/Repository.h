#pragma once

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

template <class T>
class Repository
{
public:
	T* data;
	int maxSize;
	int current;
	bool sync;
	int lastAnimalsIndex;
	int maxNrkinds = -1;
	string maxkinds = "";

	string GetStorageName() {
		T t;
		return t.GetStorageName();
	}

	void ReadFromStorage();
	void WriteToStorage();



	Repository(bool sync = false);
	~Repository();
	bool Add(T& t);
	void WriteToConsole();
	string GetMostPopularAnimal(T);

};

template <class T>
Repository<T>::Repository(bool sync)
{
	this->sync = sync;
	maxSize = 100;
	data = new T[maxSize];
	current = -1;
	ReadFromStorage();
}

template <class T>
Repository<T>::~Repository()
{
	WriteToStorage();
	delete[] data;
}

template <class T>
bool Repository<T>::Add(T& entity)
{
	data[++current] = entity;
	if (sync)
		WriteToStorage();
	return true;
}
template<class T>
void Repository<T>::ReadFromStorage() {
	ifstream fin(GetStorageName());
	char delim = ',';
	while (!fin.eof()) {
		T t;
		fin >> t;
		Add(t);
	}
	fin.close();

}

template<class T>
void Repository<T>::WriteToStorage() {
	ofstream fout(GetStorageName());
	for (int i = 0; i <= current; i++) {
		fout << data[i];
		if (i < current) {
			fout << endl;
		}

	}
	fout.close();
}

template <class T>
void Repository<T>::WriteToConsole()
{
	for (int i = 0; i <= current; i++)
	{
		cout << data[i] << endl;
	}
}
template <class T>
string Repository<T>::GetMostPopularAnimal(T)
{

	for (int i = 0; i <= lastAnimalsIndex; i++)
	{
		int nrOfMakes = 0;
		for (int j = i + 1; j <= lastAnimalsIndex; j++)
		{
			if (data[i].Getkinds() == data[j].Getkinds())
				nrOfMakes++;
		}
		if (nrOfMakes > maxNrkinds)
		{
			maxNrkinds = nrOfMakes;
			maxkinds = data[i].Getkinds();
		}
	}

	return maxkinds;
}
