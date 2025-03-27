#include "Headers/BMW.h"
#include "Headers/Car.h"
#include <iostream>

double BMW::RaceTime(double lentgh, WeatherCondition weather) {
	double speed = GetSpeed(weather);
	if (GetFuelCapacity() < lentgh * GetFuelConsumption())
	{
		std::cout << "bmw-ul nu mai merge doar cu 50 lei , e 7 lei motorina" << std::endl;
		return -1;
	}
	return lentgh / speed;
}