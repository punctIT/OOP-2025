#include <iostream>
#include "Headers/Circuit.h"
#include "Headers/Weather.h"
#include "Headers/BMW.h"
#include "Headers/Seat.h"
#include "Headers/RangeRover.h"
#include "Headers/Fiat.h"
#include "Headers/Volvo.h"
using namespace std;

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(WeatherCondition::RAIN);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); 
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}