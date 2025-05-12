#pragma once 
#include <iostream>
#include <tuple>

template <class K,class V>
class Map {
	
	struct KeyVal{
		V value;
		K key;
	}*x;
	unsigned int index;
	void resize(K val) {
		index++;
		KeyVal* x2 = new  KeyVal[index];
		for (int i = 0; i < index - 1; i++)
			x2[i] = x[i];
		delete[] x;
		x = x2;
		x[index - 1].key = val;
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
	V& operator [] (K val) {
		if (index == 0) {
			resize(val);
			return x[index - 1].value;
		}
		else {
			for (int i = 0; i < index; i++)
				if (x[i].key == val)
					return x[i].value;
			resize(val);
			return x[index - 1].value;
		}
	}



	void Set(K key,V val) {
		for (int i = 0; i < index; ++i)
			if (x[i].key == key) {
				x[i].value=val;
				return;
			}
		resize(key);
		x[index - 1].value = val;
	}
	bool Get(const K& key, V& value) {
		for(int i=0;i<index; ++i)
			if (x[i].key == key) {
				value = x[i].value;
				return true;
			}
		return false;
	}
	void print() {
		for (int i = 0; i < index; i++)
			std::cout << i << " " << x[i].key << " " << x[i].value << std::endl;
	}
	unsigned int Count() {
		return index;
	}
	void Clear() {
		delete[] x;
		index = 0;
		x = new KeyVal[index];
	}
	bool Delete(const K& key) {
		int poz = -1;
		for(int i=0;i<index;i++)
			if (x[i].key == key)
			{
				poz = i;
				break;
			}
		if (poz == -1)
			return 0;
		for (int i = poz; i < index - 1; i++)
			x[i] = x[i + 1];
		index--;
		return true;
	}
	bool Includes(const Map<K, V>& map) {
		if (map.Count() > index)
			return false;
		for (int i = 0; i < map.Count(); ++i) {
			bool este = 0;
			for (int q = 0; q < index; ++q) {
				if (x[q].key == map.x[i].key)
				{
					este = 1;
					break;
				}
			}
			if (!este)
				return false;
		}
		return true;
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
			return std::make_tuple(map.x[index].key , map.x[index].value, index);
		}
	};

	Iterator begin() const {
		return Iterator{ *this, 0 };
	}

	Iterator end() const {
		return Iterator{ *this, this->index };
	}

};