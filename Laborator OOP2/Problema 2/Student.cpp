#include "Student.h"

void student::Init()
{
	this->name[0] = '\0';
	this->math = this->english = this->history = 0;
}

void student::SetName(const char* name)
{
	int c = 0;
	while (name[c] != 0) {
		this->name[c] = name[c];
		++c;
	}
	this->name[c] = name[c];
}
void student::SetEnglishGrade(float grade){
	if (grade <= 10.0 and grade >= 1.0){
		this->english = grade;
	}
}
void student::SetHistoryGrade(float grade){
	if (grade <= 10.0 and grade >= 1.0) {
		this->history = grade;
	}
}
void student::SetMathGrade(float grade){
	if (grade <= 10.0 and grade >= 1.0) {
		this->math = grade;
	}
}
char* student::GetName() {
	return this->name;
}
float student::GetMathGrade()
{
	return this->math;
}
float student::GetHistoryGrade()
{
	return this->history;
}
float student::GetEnglishGrade()
{
	return this->math;
}
float student::Average()
{
	return float((this->english + this->history + this->math) / 3.0);
}