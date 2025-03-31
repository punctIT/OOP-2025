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
    virtual const char* GetName()=0;
    virtual double RaceTime(double lentgh, WeatherCondition weather) = 0;
};