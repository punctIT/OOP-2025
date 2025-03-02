#pragma once
#include "movie.h"
class MovieSeries {
private:
	Movie *movieSerie;
	int count;
public:
	void Init();
	void AddMovie(const Movie& movie);
	void PrintList();
	void SortList();
};
