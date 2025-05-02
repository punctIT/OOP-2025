#pragma once 
#include <iostream>
#include <tuple>

template <class T,class F>
class Map {
	
	struct KeyVal{
		F s;
		T value;
	}*x;
	unsigned int index;
	void resize(T val) {
		index++;
		KeyVal* x2 = new  KeyVal[index];
		for (int i = 0; i < index - 1; i++)
			x2[i] = x[i];
		delete[] x;
		x = x2;
		x[index - 1].value = val;
	}
public:
	Map() {
		index = 0;
		x = new  KeyVal[index];
	}
	~Map() {
		delete[] x;
		index = 0;
	}
	F& operator [] (T val) {
		if (index == 0) {
			resize(val);
			return x[index - 1].s;
		}
		else {
			for (int i = 0; i < index; i++)
				if (x[i].value == val)
					return x[i].s;
			resize(val);
			return x[index - 1].s;
		}
	}
	void print() {
		for (int i = 0; i < index; i++)
			std::cout << i << " " << x[i].s << " " << x[i].value << std::endl;
	}

	struct Iterator {
		const Map& map;
		unsigned int index;
		
		bool operator!=(const Iterator& other) const {
			return index != other.index;
		}

		Iterator& operator++() {
			index++;
			return *this;
		}

		auto operator*() const {
			return std::make_tuple(map.x[index].value , map.x[index].s, index);
		}
	};

	Iterator begin() const {
		return Iterator{ *this, 0 };
	}

	Iterator end() const {
		return Iterator{ *this, this->index };
	}

};