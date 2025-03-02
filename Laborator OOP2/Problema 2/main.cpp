#include <iostream>
#include "Student.h"
#include "OtherFuntions.h"

using namespace std;


int main()
{
	student s,s2;
	s.Init();
	s2.Init();
	s.SetName("Ion Ion");
	s2.SetName("Ion Ionu");
	cout << NameComparison(s, s2) << endl;
	s.SetEnglishGrade(5);
	s.SetHistoryGrade(3.4);
	s.SetMathGrade(4.5);
	cout << s.Average() << endl;
	cout << s2.GetMathGrade() << endl;
}