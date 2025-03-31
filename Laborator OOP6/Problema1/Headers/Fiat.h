#pragma once
#include "Car.h"

class Fiat : public Car {
public:
	Fiat() : Car("Fiat(dacia italiana)", 5, 55, 78, 45, 40.0) {}
	double RaceTime(double lentgh, WeatherCondition weather) override;
	void SetFuelCapacity(int n);
	int GetFuelCapacity();
	const char* GetName();
	void SetSpeed(WeatherCondition weather, double speed);
	double GetSpeed(WeatherCondition weather);
	double GetAvarageSpeed();
	double GetFuelConsumption();
};