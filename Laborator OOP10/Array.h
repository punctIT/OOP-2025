#pragma once
#include <iostream>
#include <exception>
#include <type_traits>

class Error_div0 : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Nu se poate impartii la 0";
	}
};

class IndexError : public std::exception
{
	virtual const char* what() const throw()
	{
		return "index invalid";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template <class T>
class Array {
private:
	int size;
	T* v;
	void resize(int n) {
		T* f = new T[n + 1];
		for (int i = 0; i < size; i++)
			f[i] = v[i];
		delete[] v;
		v = f;
	}
public:
	Array() {
		size = 0;
		v = new T[size];
	}
	Array(std::initializer_list<T> list) {
		size = list.size();
		delete[]v;
		v = new T[size];
		int i = 0;
		for (auto val : list) {
			v[i++] = val;
		}
	}
	~Array() {
		delete[]v;
		size = 0;
	}
	Array(Array&& d) {
		delete[]v;
		size = d.size;
		v = new T[size];
		for (int i = 0; i < size; i++)
			v[i] = d.v[i];
		d.size = 0;
		delete[] d.v;
	}
	Array(const Array& d) {
		delete[]v;
		size = d.size;
		v = new T[size];
		for (int i = 0; i < size; i++)
			v[i] = d.v[i];
	}

	void push(T val) {
		size += 1;
		resize(size);
		v[size - 1] = val;
	}
	void pop(T val) {
		for (int i = 0; i < size; i++) {
			if (v[i] == val) {
				for (int q = i; q < size - 1; q++) {
					v[q] = v[q + 1];
				}
				size--;
				resize(size);
			}
		}
	}
	void print() {
		for (int i = 0; i < size; ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}
	int Find(T val) {
		for (int i = 0; i < size; ++i) {
			if (val == v[i])
				return i;
		}
		return -1;
	}
	void sort() {
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for(int i=0;i<size-1;i++)
				if (v[i] > v[i + 1]) {
					T aux = v[i];
					v[i] = v[i + 1];
					v[i + 1] = aux;
					sorted = false;
				}
		}
	}
	void sort(int(*compare)(const T&, const T&)) {
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 0; i < size - 1; i++)
				if (compare(v[i],v[i+1])) {
					T aux = v[i];
					v[i] = v[i + 1];
					v[i + 1] = aux;
					sorted = false;
				}
		}
	}
	void sort(Compare* comparator) {

	}
	Array& operator += (T val) {
		for (int i = 0; i < size; i++)
			v[i] += val;
		return *this;
	}
	Array& operator -= (T val) {
		for (int i = 0; i < size; i++)
			v[i] -= val;
		return *this;
	}
	T operator [](int i) {
		if (i < 0 || i>size)
			throw IndexError();
		return v[i];
	}
	Array& operator /= (T val) {
		
		if (val == 0) {
			throw Error_div0();
		}
		for (int i = 0; i < size; ++i) {
			v[i] /= val;
		}
		return *this;
	}
	Array& operator *= (T val) {
		
		for (int i = 0; i < size; ++i) {
			v[i] *= val;
		}
		return *this;
	}
};
