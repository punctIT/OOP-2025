#include "Headers/Fiat.h"
#include <iostream>

double Fiat::RaceTime(double lentgh, WeatherCondition weather) {
	double speed = GetSpeed(weather);
	if (GetFuelCapacity() < lentgh * GetFuelConsumption())
	{
		return -1;
	}
	return lentgh / speed;

}
void Fiat::SetFuelCapacity(int n) {
    this->FuelCapacity = n;
}
int Fiat::GetFuelCapacity() {
    return this->FuelCapacity;
}
const char* Fiat::GetName() {
    return this->Name;
}
void Fiat::SetSpeed(WeatherCondition weather, double speed) {
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
double Fiat::GetSpeed(WeatherCondition weather) {
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

double Fiat::GetAvarageSpeed() {
    return this->AvarageSpeed;
}
double Fiat::GetFuelConsumption()
{
    return this->FuelConsumption;
}