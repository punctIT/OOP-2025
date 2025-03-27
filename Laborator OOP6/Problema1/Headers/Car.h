#pragma once
#include "Weather.h"

class Car {
protected:
    int FuelCapacity;
    double FuelConsumption;
    double AvarageSpeed;
    double speedRain;
    double speedSunny;
    double speedSnow;
    const char* Name;
public:
    Car(const char* model, int fuelC, double SpeedR, double SpeedSu, double SpeedSn, double fuelCons)
        : Name(model), FuelCapacity(fuelC), FuelConsumption(fuelCons),
        AvarageSpeed((SpeedR + SpeedSu + SpeedSn) / 3),
        speedRain(SpeedR), speedSnow(SpeedSn), speedSunny(SpeedSu) {
    }
    virtual ~Car() {}
    void SetFuelCapacity(int n) {
        this->FuelCapacity = n;
    }
    int GetFuelCapacity() {
        return this->FuelCapacity;
    }
    const char* GetName() {
        return this->Name;
    }
    void SetSpeed(WeatherCondition weather, double speed) {
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
    double GetSpeed(WeatherCondition weather) {
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

    double GetAvarageSpeed() {
        return this->AvarageSpeed;
    }
    double GetFuelConsumption()
    {
        return this->FuelConsumption;
    }
    virtual double RaceTime(double lentgh, WeatherCondition weather) = 0;
};