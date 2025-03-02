#include "movie.h"
#include <ctime>


void Movie::Init() {
	this->name[0] = '\0';
	this->releseYear = 0;
	this->scoreIMDB = 0;
	this->lentgh = 0;
}
void Movie::SetName(const char* name)
{
	int c = 0;
	while (name[c])
	{
		this->name[c] = name[c];
		++c;
	}
	this->name[c] = name[c];
}
void Movie::SetReleseYear(unsigned year)
{
	this->releseYear = year;
}
void Movie::SetScoreIMDB(double score){
	if (score >= 1.0 and score <= 10.0){
		this->scoreIMDB = score;
	}
}
void Movie::SetMovieLength(unsigned lentgh) {
	this->lentgh = lentgh;
}
char *Movie::GetName(){
	return this->name;
}
unsigned Movie::GetReleseYear() {
	return this->releseYear;
}
unsigned Movie::GetMovieLength() {
	return this->lentgh;
}
double Movie::GetScoreIMDB() {
	return this->scoreIMDB;
}
int Movie::GetNumberOfPassedYears()
{
	std::time_t t = std::time(nullptr); 
	std::tm now{}; 
	localtime_s(&now, &t); 
	int year = now.tm_year + 1900; 
	return year-this->releseYear;
}