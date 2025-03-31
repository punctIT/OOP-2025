#include "Headers/BMW.h"
#include "Headers/Car.h"
#include <iostream>

double BMW::RaceTime(double lentgh, WeatherCondition weather) {
	double speed = GetSpeed(weather);
	if (GetFuelCapacity() < lentgh * GetFuelConsumption())
	{
		std::cout << "bmw-ul nu mai merge doar cu 50 lei , e 7 lei motorina" << std::endl;
		return -1;
	}
	return lentgh / speed;
}
void BMW::SetFuelCapacity(int n) {
    this->FuelCapacity = n;
}
int BMW::GetFuelCapacity() {
    return this->FuelCapacity;
}
const char* BMW::GetName() {
    return this->Name;
}
void BMW::SetSpeed(WeatherCondition weather, double speed) {
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
double BMW::GetSpeed(WeatherCondition weather) {
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

double BMW::GetAvarageSpeed() {
    return this->AvarageSpeed;
}
double BMW::GetFuelConsumption()
{
    return this->FuelConsumption;
}