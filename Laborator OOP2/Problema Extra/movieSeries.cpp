#include "movieSeries.h"
#include <iostream>

void swap(Movie*& a, Movie*& b)
{
	Movie* aux = a;
	a = b;
	b = aux;
}

void MovieSeries::Init() {
	this->count = 0;
	for (int i = 0; i < 16; i++)
		this->movieSerie[i] = new Movie();
}
void MovieSeries::AddMovie(Movie *movie) {
	this->movieSerie[this->count++] = movie;
}
void MovieSeries::PrintList() {
	for (int i = 0; i < this->count; i++) {
		std::cout << this->movieSerie[i]->GetName()
			<< " " << this->movieSerie[i]->GetReleseYear()
			<< " " << this->movieSerie[i]->GetScoreIMDB()
			<< " " << this->movieSerie[i]->GetMovieLength()
			<< std::endl;
	}
}
void MovieSeries::SortList() {
	while (true) {
		bool isSorted = true;
		for (int i = 0; i < this->count - 1; i++)
		{
			if (this->movieSerie[i]->GetNumberOfPassedYears() < this->movieSerie[i + 1]->GetNumberOfPassedYears()) {
				swap(this->movieSerie[i], this->movieSerie[i + 1]);
				isSorted = false;
			}
		}
		if (isSorted)
			return;
	}
}