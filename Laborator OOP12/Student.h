#pragma once
#include "Materie.h"
#include <vector>
#include <memory>
#include <string>
class Student {
	std::vector <std::shared_ptr<Materie>> materii;
	std::string nume;
	std::string numar_maticol;
	std::string program_studii;
public:

	Student(std::string name, std::string numar_matricol) {
		this->nume = name;
		this->numar_maticol = numar_matricol;
	}
	void adauga_materie(Materie* s) {
		materii.push_back(std::shared_ptr<Materie>(s));
	}
	std::string GetName() {
		return this->nume;
	}
	std::string GetMatricol() {
		return this->numar_maticol;
	}
	std::vector <std::shared_ptr<Materie>> GetMaterii() {
		return this->materii;
	}
	float GetMedie() {
		float sum = 0;
		for (auto i : materii) {
			sum += i->GetGradesAvarage();
		}
		return sum / materii.size();
	}
};