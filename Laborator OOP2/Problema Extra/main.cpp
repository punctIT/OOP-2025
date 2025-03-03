#include "movie.h"
#include "movieSeries.h"
#include "otherFunctions.h"
#include <iostream>

using namespace std;

int main() {
    Movie ep5;
    ep5.SetName("Star Wars: Episode V - The Empire Strikes Back");
    ep5.SetScoreIMDB(8.7);
    ep5.SetReleseYear(1980);
    ep5.SetMovieLength(124);

    Movie ep4;
    ep4.SetName("Star Wars: Episode IV - A New Hope");
    ep4.SetScoreIMDB(8.6);
    ep4.SetReleseYear(1977);
    ep4.SetMovieLength(121);

    Movie ep6;
    ep6.SetName("Star Wars: Episode VI - Return of the Jedi");
    ep6.SetScoreIMDB(8.3);
    ep6.SetReleseYear(1983);
    ep6.SetMovieLength(131);

    printf(
        R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d
passed years: %d
)",
NameComparison(ep4, ep5),
ReleseYearComparison(ep4, ep5),
ScoreIMDBComparison(ep4, ep5),
MovieLengthComparison(ep4, ep5),
PassedYearsComparison(ep4, ep5));

    MovieSeries series;
    series.Init();
    series.AddMovie(&ep5);
    series.AddMovie(&ep4);
    series.AddMovie(&ep6);

    series.SortList();
    series.PrintList();
}
