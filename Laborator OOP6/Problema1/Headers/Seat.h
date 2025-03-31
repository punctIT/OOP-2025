#pragma once
#include "Car.h"

class Seat : public Car {
public:
	Seat() : Car("Seat", 2000, 1150, 1300, 1200, 10.0) {}
	double RaceTime(double lentgh, WeatherCondition weather) override;
	void SetFuelCapacity(int n);
	int GetFuelCapacity();
	const char* GetName();
	void SetSpeed(WeatherCondition weather, double speed);
	double GetSpeed(WeatherCondition weather);
	double GetAvarageSpeed();
	double GetFuelConsumption();
};