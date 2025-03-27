#pragma once

#include <iostream>
#include "Car.h"
#include "Weather.h"

class Circuit{
private:
	double lentgh;
	WeatherCondition weather;
	int size;
	Car* cars[20];
	struct {
		char* name;
		double time;
	}times[120];
public:
	Circuit() : size(0) {};
	~Circuit();
	void Race();
	void AddCar(Car *car);
	void SetLength(double lentgh);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void SetWeather(WeatherCondition weather);
};