#include "Headers/Seat.h"
#include <iostream>

double Seat::RaceTime(double lentgh, WeatherCondition weather) {
	double speed = GetSpeed(weather);
	if (GetFuelCapacity() < lentgh * GetFuelConsumption())
	{
		return -1;
	}
	return lentgh / speed;
}