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
void Seat::SetFuelCapacity(int n) {
    this->FuelCapacity = n;
}
int Seat::GetFuelCapacity() {
    return this->FuelCapacity;
}
const char* Seat::GetName() {
    return this->Name;
}
void Seat::SetSpeed(WeatherCondition weather, double speed) {
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
double Seat::GetSpeed(WeatherCondition weather) {
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

double Seat::GetAvarageSpeed() {
    return this->AvarageSpeed;
}
double Seat::GetFuelConsumption()
{
    return this->FuelConsumption;
}