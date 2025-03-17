#include "Sort.h"
#include <iostream>

using namespace std;

int main() {
	Sort s(10,100,999);
	s.Print();
	s.BubbleSort(true);
	s.Print();
	cout << endl;
	
	int v[] = { 5,3,4,6,8,3,1,6,54,34,34 };
	Sort s2(v, 11);
	s2.BubbleSort();
	s2.Print();

	cout << endl;

	Sort s3(10, 1, 2, 4, 323, 457, 12, 86, 2, 6, 3);
	s3.InsertSort(true);
	s3.Print();
	cout << endl;

	Sort s5("10,20,42,42,341,342,123,555,232");
	s5.BubbleSort();
	s5.Print();
	

	cout << endl;

	Sort s4 = { 6 ,24,5,2,35,23,53 };
	s4.BubbleSort();
	s4.Print();

}