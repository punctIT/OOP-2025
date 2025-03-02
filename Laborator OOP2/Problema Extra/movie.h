#pragma once

class Movie {
private:
	char name[256];
	unsigned releseYear;
	double scoreIMDB;
	unsigned lentgh;
public:
	void Init();
	void SetName(const char* name);
	void SetReleseYear(unsigned year);
	void SetScoreIMDB(double score);
	void SetMovieLength(unsigned length);

	char* GetName();
	unsigned GetReleseYear();
	unsigned GetMovieLength();
	double GetScoreIMDB();
	int GetNumberOfPassedYears();

};