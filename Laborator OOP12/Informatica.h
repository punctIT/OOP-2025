#pragma once 
#include "Materie.h"


#include <vector>
class Informatica : public Materie {

public:
	Informatica(std::initializer_list<float> initList);
	virtual float GetGradesAvarage() override;
	virtual std::string GetName() override;
	virtual void print() override;
};