#pragma once 
#include <string>
#include <vector>

class Materie {
protected:
	std::vector <float> grades;
	std::string name;
	int numar_credite;
	bool facultativ;
	bool optional;
	bool obligatori;
public:
	virtual float GetGradesAvarage() = 0;
	virtual std::string GetName() = 0;
	virtual void print() = 0;
};