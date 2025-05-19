#pragma once
#include <string>
#include "pch.h"
template <class T>
class Array {
	int size;
	T* v;
public:
	Array(std::initializer_list<T> list) {
		size = list.size();
		v = new T[size];
		int i = 0;
		for (auto val : list) {
			v[i++] = val;
		}
	}
	~Array() {
		delete[] v;
	}
	T sort(bool crescator = true) {
		bool is_sorted = false;
		while (!is_sorted) {
			is_sorted = true;
			for (int i = 1; i < size - 1; i += 2) {
				if (!crescator) {
					if (v[i] > v[i] + 1) {
						T aux = v[i];
						v[i] = v[i + 1];
						v[i + 1] = aux;
						is_sorted = false;
					}
				}
				else {
					if (v[i] < v[i + 1]) {
						T aux = v[i];
						v[i] = v[i] + 1;
						v[i + 1] = aux;
						is_sorted = false;
					}
				}
			}
		}

		return v[0];
	}
	void sortGOOD(bool decreasing = false) {
		bool is_sorted = false;
		while (!is_sorted) {
			is_sorted = true;
			for (int i = 0; i < size - 1; i++) {
				if (!decreasing) {
					if (v[i] > v[i + 1]) {
						T aux = v[i];
						v[i] = v[i + 1];
						v[i + 1] = aux;
						is_sorted = false;
					}
				}
				else {
					if (v[i] < v[i + 1]) {
						T aux = v[i];
						v[i] = v[i + 1];
						v[i + 1] = aux;
						is_sorted = false;
					}
				}
			}
		}
	}

	std::string print() {
		std::string f = "";
		for (int i = 0; i < size; i++) {
			f += std::to_string(v[i]);
			f += ' ';
		}
		return f;
	}

};