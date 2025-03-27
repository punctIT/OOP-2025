#include "Headers/Volvo.h"
#include <iostream>

double Volvo::RaceTime(double lentgh, WeatherCondition weather) {
	double speed = GetSpeed(weather);
	if (GetFuelCapacity() < lentgh * GetFuelConsumption())
	{
		return -1;
	}
	return lentgh / speed;
}