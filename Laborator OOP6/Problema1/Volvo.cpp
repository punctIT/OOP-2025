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
void Volvo::SetFuelCapacity(int n) {
    this->FuelCapacity = n;
}
int Volvo::GetFuelCapacity() {
    return this->FuelCapacity;
}
const char* Volvo::GetName() {
    return this->Name;
}
void Volvo::SetSpeed(WeatherCondition weather, double speed) {
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
double Volvo::GetSpeed(WeatherCondition weather) {
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

double Volvo::GetAvarageSpeed() {
    return this->AvarageSpeed;
}
double Volvo::GetFuelConsumption()
{
    return this->FuelConsumption;
}