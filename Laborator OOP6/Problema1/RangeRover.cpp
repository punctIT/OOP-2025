#include "Headers/RangeRover.h"
#include <iostream>

double RangeRover::RaceTime(double lentgh, WeatherCondition weather) {
	double speed = GetSpeed(weather);
	if (GetFuelCapacity() < lentgh * GetFuelConsumption())
	{
		return -1;
	}
	return lentgh / speed;
}
void RangeRover::SetFuelCapacity(int n) {
    this->FuelCapacity = n;
}
int RangeRover::GetFuelCapacity() {
    return this->FuelCapacity;
}
const char* RangeRover::GetName() {
    return this->Name;
}
void RangeRover::SetSpeed(WeatherCondition weather, double speed) {
    if (weather == WeatherCondition::RAIN) {
        this->speedRain = speed;
    }
    if (weather == WeatherCondition::SUNNY) {
        this->speedSunny = speed;
    }
    if (weather == WeatherCondition::SNOW) {
        this->speedSnow = speed;
    }
}
double RangeRover::GetSpeed(WeatherCondition weather) {
    if (weather == WeatherCondition::RAIN) {
        return this->speedRain;
    }
    if (weather == WeatherCondition::SUNNY) {
        return this->speedSunny;
    }
    if (weather == WeatherCondition::SNOW) {
        return this->speedSnow;
    }
}

double RangeRover::GetAvarageSpeed() {
    return this->AvarageSpeed;
}
double RangeRover::GetFuelConsumption()
{
    return this->FuelConsumption;
}