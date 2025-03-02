#include "movie.h"


int NameComparison(Movie a, Movie b) {
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
int ReleseYearComparison(Movie a, Movie b) {
	if (a.GetReleseYear() > b.GetReleseYear())
		return 1;
	if (a.GetReleseYear() < b.GetReleseYear())
		return -1;
	return 0;
}
int ScoreIMDBComparison(Movie a, Movie b) {
	if (a.GetScoreIMDB() > b.GetScoreIMDB())
		return 1;
	if (a.GetScoreIMDB() < b.GetScoreIMDB())
		return -1;
	return 0;
}
int MovieLengthComparison(Movie a, Movie b) {
	if (a.GetMovieLength() > b.GetMovieLength())
		return 1;
	if (a.GetMovieLength() < b.GetMovieLength())
		return -1;
	return 0;
}
int PassedYearsComparison(Movie a, Movie b) {
	int p1 = a.GetNumberOfPassedYears();
	int p2 = b.GetNumberOfPassedYears();
	if (p1 > p2)
		return 1;
	if (p1 < p2)
		return -1;
	return 0;
}