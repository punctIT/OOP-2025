#include "Informatica.h"
#include <iostream>
Informatica::Informatica(std::initializer_list<float> initList)
{
    this->name = "Informatica";
    this->optional = false;
    this->obligatori = true;
    this->facultativ = false;
    for (auto i : initList) {
        this->grades.push_back(i);
    }
}

float Informatica::GetGradesAvarage()
{
    float sum = 0;
    for (auto i : this->grades)
    {
        sum += i;
    }
    return sum / this->grades.size();
}

std::string Informatica::GetName()
{
    return this->name;
}

void Informatica::print()
{
    for (auto i : this->grades) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}

