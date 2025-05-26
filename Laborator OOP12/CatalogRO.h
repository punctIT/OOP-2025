#pragma once;
#include "Catalog.h"
#include "Student.h"
#include <vector> 
#include <memory>
#include <iostream> 
#include <algorithm>

class CatalogRO :public Catalog {
	std::vector <std::shared_ptr<Student>> studenti;
public:
	virtual void AddStudent(Student* s) override {
		studenti.push_back(std::shared_ptr<Student>(s));
	}
	virtual void ListStudent() override {
		for (auto i : studenti) {
			std::cout << i->GetName() << " " << i->GetMatricol() << std::endl;
			for (auto w : i->GetMaterii()) {
				std::cout << w->GetName() << " ";
				w->print();
			}
			
			std::cout << std::endl;
		}
	}
	virtual void RankStudent() override {
		//sort(this->studenti.begin(), this->studenti.end(), [](Student *a, Student *b) {return a->GetMedie() < b->GetMedie(); });
	}
	virtual void GetGradesStudent(std::string name) override {
		
		for (auto i : studenti) {
			if (i->GetName() == name) {
				std::cout << "Studentul {" << name << "} are notele" << std::endl;
				for (auto w : i->GetMaterii()) {
					std::cout << w->GetName() << " ";
					w->print();
					
				}
				std::cout << "media generala "  << i->GetMedie() << std::endl;	
			}
		}
	}
	virtual float Avarage()  override {
		float a = 0.2;
		return a;
	}
};