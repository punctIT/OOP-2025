#include <iostream>
#include "NumberList.h"


void swap(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}

void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	if (this->count >= 10) {
		std::cout << "Lista e plina";
		return false;
	}
		
	this->numbers[this->count] = x;
	this->count++;
}
void NumberList::Sort()
{
	while (true)
	{
		bool isSorted = true;
		for(int i=0;i<this->count-1;i++)
			if (this->numbers[i] > this->numbers[i + 1])
			{
				isSorted = false;
				swap(this->numbers[i], this->numbers[i + 1]);
			}
		if (isSorted)
			return;
	}
}
void NumberList::Print() {
	for (int i = 0; i < this->count; i++)
		std::cout << this->numbers[i] << " ";
	std::cout << '\n';
}