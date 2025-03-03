#pragma once
#include "movie.h"
class MovieSeries {
private:
	Movie* movieSerie[16];
	int count;
public:
	void Init();
	void AddMovie(Movie *movie);
	void PrintList();
	void SortList();
};