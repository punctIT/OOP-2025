#pragma once
class Number
{
	char* number;
	int base;

public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int i);
	~Number();



	friend Number operator+(const Number& i, const Number& q);
	friend Number operator-(const Number& i, const Number& q);
	char operator[](int i);
	Number(const Number& other);
	Number& operator=(int value);
	Number& operator=(const char* str);
	Number& operator+=(const Number &i);
	bool operator>(Number& i);
	bool operator<(Number& i);
	bool operator>=(Number& i);
	bool operator<=(Number& i);
	bool operator==(Number& i);

	Number operator--(int val);
	Number& operator--();


	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount(); // returns the number of digits for the current number
	int GetBase(); // returns the current base
};