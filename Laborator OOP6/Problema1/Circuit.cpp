#include "Headers/Circuit.h"
#include "Headers/Car.h"
#include <iostream>
#include <cstring>
#include "Headers/Weather.h"



void Circuit::Race() {
	for (int i = 0; i < this->size; ++i)
	{
		times[i].time = this->cars[i]->RaceTime(this->lentgh, this->weather);
		times[i].name = new char[strlen(this->cars[i]->GetName())];
		strcpy_s(times[i].name,1+ strlen(this->cars[i]->GetName()),this->cars[i]->GetName());
	}
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for(int i=0;i<this->size-1;i++)
			if (this->times[i].time > this->times[i + 1].time) {
				double aux = this->times[i].time;
				this->times[i].time = this->times[i + 1].time;
				this->times[i + 1].time = aux;
				std::swap(this->times[i + 1].name, this->times[i].name);
				isSorted = false;
			}
	}
}
void Circuit::SetLength(double lentgh) {
	this->lentgh = lentgh;
}
void Circuit::AddCar(Car* car){
	cars[this->size] = car;
	this->size++;
}
void Circuit::SetWeather(WeatherCondition Weather) {
	this->weather = Weather;
}
void Circuit::ShowFinalRanks() {
	std::cout << "Winners" << std::endl;
	for (int i = 0; i < this->size; ++i)
		if(times[i].time!=-1)
			std::cout << times[i].name << " " << times[i].time << std::endl;
}
void Circuit::ShowWhoDidNotFinish() {
	std::cout << "DNF" << std::endl;
	for (int i = 0; i < this->size; ++i)
		if (times[i].time == -1)
			std::cout << times[i].name << " " << times[i].time << std::endl;
}
Circuit ::~Circuit() {
	
}