#pragma once
#include "Student.h"
#include <string>
class Catalog {
public:
	virtual void RankStudent() = 0;
	virtual void AddStudent(Student *s) = 0;
	virtual void GetGradesStudent(std::string name) = 0;
	virtual float Avarage() = 0;
	virtual void ListStudent() = 0;
};