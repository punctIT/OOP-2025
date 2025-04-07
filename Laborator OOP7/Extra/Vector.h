#include <iostream>
template <class T>
class Vector {
	int size;
	T* x;

public:
	Vector() {
		size = 0;
		x = new T[size];
	}
	Vector(const Vector& v) {
		size = v.size;
		x = new T[size];
		for (int i = 0; i < size; ++i)
			x[i] = v.x[i];
	}
	~Vector() {
		delete[] x;
	}
	void insert(int p, T e) {
		if (p < size)
			x[p] = e;
		else {
			T* nx = new T[p + 1];
			for (int i = 0; i < size; i++) {
				nx[i] = x[i];
			}
			nx[p] = e;
			size = p + 1;
			delete[] x;
			x = nx;
		}
	}
	void remove(int p) {
		int c = 0;
		T* nx = new T[size];
		for (int i = 0; i < size; i++) {
			if(i!=p)
				nx[c++] = x[i];
		}
		delete[]x;
		size --;
		x = nx;
	}
	void sort(int (*cmp)(T, T)) {
		bool isSorted = false;
		while (!isSorted) {
			isSorted = true;
			for(int i=0;i<size-1;i++)
				if (cmp(x[i], x[i + 1]) == 1)
				{
					isSorted = false;
					T aux = x[i];
					x[i] = x[i + 1];
					x[i + 1] = aux;
				}
		}
	}
	void print() {
		for (int i = 0; i < size; i++)
			std::cout << x[i] << " ";

	}
	T operator [](int f) {
		return this->x[f];
	}
};