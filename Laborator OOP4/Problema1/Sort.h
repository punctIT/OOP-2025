#pragma once
class Sort {
	int* array;
	int size;
public:
	//add constructors
	Sort(int n, int min, int max);
	Sort(int n, int* a) : size(n), array(a) {};
	Sort(int v[], int n);
	Sort(int n,...);
	Sort(const char *numbers);
	//cursul de maine 
	~Sort();

	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);
};