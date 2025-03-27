#pragma once
#include "Car.h"

class RangeRover : public Car {
public:
	RangeRover() : Car("Range Rover", 2090, 150, 300, 200, 10.0) {}
	double RaceTime(double lentgh, WeatherCondition weather) override;
};