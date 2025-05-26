#include "Math.h"
#include <iostream>
Math::Math(std::initializer_list<float> initList)
{
    this->name = "Matematica";
    this->optional = false;
    this->obligatori = true;
    this->facultativ = false;
    for (auto i : initList) {
        this->grades.push_back(i);
    }
}

float Math::GetGradesAvarage()
{
    float sum = 0;
    for (auto i : this->grades)
    {
        sum += i;
    }
    return sum/this->grades.size();
}

std::string Math::GetName()
{
    return this->name;
}

void Math::print()
{
    for (auto i : this->grades) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
}

