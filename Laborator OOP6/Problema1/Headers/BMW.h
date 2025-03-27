#pragma once
#include "Car.h"

class BMW : public Car{
public:
	BMW() : Car("BMW M6", 2000, 150, 300, 200, 10.0) {} 
	double RaceTime(double lentgh, WeatherCondition weather) override;
};