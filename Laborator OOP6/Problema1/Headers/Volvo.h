#pragma once
#include "Car.h"

class Volvo : public Car {
public:
	Volvo() : Car("Volvo", 200, 150, 300, 200, 10.0) {}
	double RaceTime(double lentgh, WeatherCondition weather) override;
	void SetFuelCapacity(int n);
	int GetFuelCapacity();
	const char* GetName();
	void SetSpeed(WeatherCondition weather, double speed);
	double GetSpeed(WeatherCondition weather);
	double GetAvarageSpeed();
	double GetFuelConsumption();
};