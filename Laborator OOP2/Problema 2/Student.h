#pragma once

class student {
private:
	char name[51];
	float math, english, history;
public:
	void Init();
	void SetName(const char *name);
	void SetMathGrade(float grade);
	void SetEnglishGrade(float grade);
	void SetHistoryGrade(float grade);
	char* GetName();
	float GetMathGrade();
	float GetEnglishGrade();
	float GetHistoryGrade();
	float Average();
};