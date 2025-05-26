#pragma once 
#include "Materie.h"


#include <vector>
class Math : public Materie {
	
public:
	Math(std::initializer_list<float> initList);
	virtual float GetGradesAvarage() override;
	virtual std::string GetName() override;
	virtual void print() override;
};