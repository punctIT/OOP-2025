#pragma once
#include "Car.h"

class Volvo : public Car {
public:
	Volvo() : Car("Volvo", 200, 150, 300, 200, 10.0) {}
	double RaceTime(double lentgh, WeatherCondition weather) override;
};