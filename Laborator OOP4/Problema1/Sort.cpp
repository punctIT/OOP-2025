#include "Sort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdarg>
Sort::Sort(int n, int min, int max)
{
	this->size = n;
	this->array = new int[n];
	srand(NULL);
	for (int i = 0; i < n; ++i){
		this->array[i]=rand() % max + min;
	}
}

Sort::Sort(int v[], int n)
{
	this->size = n;
	this->array = new int[n];
	for (int i = 0; i < n; ++i)
		this->array[i] = v[i];
}
Sort::Sort(int n, ...)
{
	this->size = n;
	this->array = new int[n];
	va_list va;
	va_start(va, n);
	for (int i = 0; i < n; i++) {
		this->array[i] = va_arg(va, int);
	}
	va_end(va);
}
Sort::Sort(const char *numbers){
	int i = 0,nr=0,cnt=0;
	this->size = 0;
	this->array = new int[100];
	while (numbers[i] != 0) {
		if (numbers[i] >= '0' && numbers[i] <= '9'){
			nr = nr * 10 + numbers[i] - '0';
		}
		else {
			this->array[this->size++] = nr;
			nr=0;
		}
		++i;
	}
	this->array[this->size++] = nr;
}
void Sort::InsertSort(bool ascendent )
{
	for (int i = 1; i < this->size; ++i) {
		int key = this->array[i];
		int j = i - 1;
		if (ascendent) {
			while (j >= 0 && this->array[j] > key) {
				this->array[j + 1] = this->array[j];
				j = j - 1;
			}
		}
		else {
			while (j >= 0 && this->array[j] < key) {
				this->array[j + 1] = this->array[j];
				j = j - 1;
			}
		}
		this->array[j + 1] = key;
	}
}
void swap(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}
int partition(int arr[], int low, int high,int ascendent) {

	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (ascendent)
		{
			if (arr[j] < pivot) {
				i++;
				swap(arr[i], arr[j]);
			}
		}
		else {
			if (arr[j] > pivot) {
				i++;
				swap(arr[i], arr[j]);
			}
		}	
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}
void quickSort(int arr[], int low, int high,int ascendent) {
	if (low < high) {
		int pi = partition(arr, low, high,ascendent);
		quickSort(arr, low, pi - 1,ascendent);
		quickSort(arr, pi + 1, high,ascendent);
	}
}
void Sort::QuickSort(bool ascendent) {
	quickSort(this->array, 0, this->size-1,ascendent);
}


void Sort::BubbleSort(bool ascendent ) {
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for(int i=0;i<this->size-1;++i)
			if (ascendent) {
				if (this->array[i] > this->array[i + 1])
				{
					swap(this->array[i], this->array[i + 1]);
					isSorted = false;
				}
			}
			else {
				if (this->array[i] < this->array[i + 1])
				{
					swap(this->array[i], this->array[i + 1]);
					isSorted = false;
				}
			}
	}
}
void Sort::Print() {
	for(int i=0;i<this->size;i++)
		std::cout<<this->array[i]<<" ";
	std::cout << std::endl;
}
Sort::~Sort()
{
	delete[] this->array;
}
int Sort::GetElementsCount() {
	return this->size;
}
int Sort::GetElementFromIndex(int index) {
	if (index < 0 || index >= this->size)
		return -1;
	else return this->array[index];
}
