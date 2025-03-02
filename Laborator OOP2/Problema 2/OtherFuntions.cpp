#include "OtherFuntions.h"

int NameComparison(student a, student b) {
	const char* name1 = a.GetName(), * name2 = b.GetName();
	int c = 0;
	while (name1[c] and name2[c])
	{
		if (name1[c] > name2[c])
			return 1;
		if (name1[c] < name2[c])
			return -1;
		++c;
	}
	if (name1[c])
		return 1;
	if (name2[c])
		return -1;
	return 0;
}
int MathGradeComparison(student a, student b) {
	if (a.GetMathGrade() > b.GetMathGrade())
		return 1;
	if (a.GetMathGrade() < b.GetMathGrade())
		return -1;
	return 0;
}
int HistoryGradeComparison(student a, student b) {
	
	if (a.GetHistoryGrade() > b.GetHistoryGrade())
		return 1;
	if (a.GetHistoryGrade() < b.GetHistoryGrade())
		return -1;
	return 0;
}
int EnglishGradeComparison(student a, student b) {
	if (a.GetEnglishGrade() > b.GetEnglishGrade())
		return 1;
	if (a.GetEnglishGrade() < b.GetEnglishGrade())
		return -1;
	return 0;
}
int AvaregeComparation(student a, student b) {
	int av1 = a.Average(), av2 = b.Average();
	if (av1 > av2)
		return 1;
	if (av1 < av2)
		return -1;
	return 0;
}