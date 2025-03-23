#include "Number.h" 
#include <iostream> 
#include <cstring> 
#include <cstdlib>
int max(int x, int y) {
	if (x > y)
		return x;
	return y;
}

Number::Number(const Number& other) {
	this->base = other.base;
	int length = strlen(other.number);
	this->number = new char[length + 1];
	strcpy_s(this->number, length + 1, other.number);
}

bool Number::operator>(Number& i) {
	Number i2(i), q2(*this);
	i2.SwitchBase(10);
	q2.SwitchBase(10);
	int nr1 = atoi(i2.number);
	int nr2 = atoi(q2.number);
	if (nr1 > nr2)
		return 1;
	return 0;
}
bool Number::operator<(Number& i) {
	Number i2(i), q2(*this);
	i2.SwitchBase(10);
	q2.SwitchBase(10);
	int nr1 = atoi(i2.number);
	int nr2 = atoi(q2.number);
	if (nr1 < nr2)
		return 1;
	return 0;
}
bool Number::operator>=(Number& i) {
	Number i2(i), q2(*this);
	i2.SwitchBase(10);
	q2.SwitchBase(10);
	int nr1 = atoi(i2.number);
	int nr2 = atoi(q2.number);
	if (nr1 >= nr2)
		return 1;
	return 0;
}
bool Number::operator<=(Number& i) {
	Number i2(i), q2(*this);
	i2.SwitchBase(10);
	q2.SwitchBase(10);
	int nr1 = atoi(i2.number);
	int nr2 = atoi(q2.number);
	if (nr1 <= nr2)
		return 1;
	return 0;
}
bool Number::operator==(Number& i) {
	Number i2(i), q2(*this);
	i2.SwitchBase(10);
	q2.SwitchBase(10);
	int nr1 = atoi(i2.number);
	int nr2 = atoi(q2.number);
	if (nr1 == nr2)
		return 1;
	return 0;
}
Number& Number::operator=(int i) {
	this->base = 10;
	delete[] this->number;
	int v[100], c = 0;
	while (i)
		v[++c] = i % 10, i /= 10;
	this->number = new char[c + 1];
	for (int q = 0; q < c; q++) {
		this->number[q] = v[c - q] + '0';
	}
	this->number[c] = 0;
	return (*this);
}
Number& Number::operator=(const char*s) {
	this->base = 10;
	delete[] this->number;
	this->number = new char[strlen(s)];
	for (int q = 0; q <= strlen(s); q++) {
		this->number[q] = s[q];
	}
	return (*this);
}
Number& Number::operator+=(const Number& i) {
	*this = *this + i;
    return *this;
}
Number& Number::operator--() {
	for (int i = 0; i < strlen(this->number); i++)
		this->number[i] = this->number[i + 1];
	return *this;
}
Number Number:: operator--(int val){
	this->number[strlen(this->number) - val-1] = 0;
	return *this;
}
char Number::operator[](int i) {
	return this->number[i];
}

Number::Number(const char* value, int base) {
	this->base = base;
	int c = 0;
	while (value[c]!=0)
		++c;
	this->number = new char[c + 1];
	c = 0;
	while (value[c])
		this->number[c] = value[c],++c;
	this->number[c] = 0;
}

Number::Number(int x) {
	this->base = 10;
	int n = 0,c=0;
	while (x)
		n = n * 10 + x % 10, x /= 10,c++;
	x = 0;
	this->number = new char[c + 1];
	while (n) {
		this->number[x] = n % 10 + '0';
		n /= 10;
		++x;
	}
	this->number[x] = 0;
}
Number::~Number()
{
	this->number = nullptr;
	this->base = 0;
}



Number operator+(const Number& i, const Number& q) {
	int base = max(i.base, q.base);
	Number i2(i), q2(q);
	i2.SwitchBase(10);
	q2.SwitchBase(10);
	int nr1 = atoi(i2.number);
	int nr2 = atoi(q2.number);
	int result = nr1 + nr2;
	delete[] i2.number;
	i2.number = new char[12];

	sprintf_s(i2.number, 12, "%d", result);
	i2.base = base;
	i2.SwitchBase(base);

	return i2;
}

Number operator-(const Number& i, const Number& q) {
	int base = max(i.base, q.base);
	Number i2(i), q2(q);
	i2.SwitchBase(10);
	q2.SwitchBase(10);
	int nr1 = atoi(i2.number);
	int nr2 = atoi(q2.number);
	int result = nr1 - nr2;
	delete[] i2.number;
	i2.number = new char[12]; 

	sprintf_s(i2.number, 12, "%d", result);
	i2.base = base;
	i2.SwitchBase(base);

	return i2;
}

int letter(char a) {
	return a - 'A' + 10;  
}

char CharLetter(int a) {
	return a + 'A' - 10;
}

void inverseaza_sir(char* sir, int lungime) {
	for (int i = 0; i < lungime / 2; i++) {
		char temp = sir[i];
		sir[i] = sir[lungime - i - 1];
		sir[lungime - i - 1] = temp;
	}
}

void Number::SwitchBase(int val) {
	if (val < 2) {
		return;
	}

	int nr = 0;
	int v = 1;

	for (int i = GetDigitsCount() - 1; i >= 0; --i) {
		if (this->number[i] >= '0' && this->number[i] <= '9') {
			nr += v * (this->number[i] - '0');
		}
		else {
			int f = letter(this->number[i]);
			nr += v * f;
		}
		v *= this->base;
	}

	this->base = val;

	if (this->number) {
		delete[] this->number;
		this->number = nullptr;
	}


	int cnt = 0, aux = nr;
	if (nr == 0) cnt = 1;
	while (aux) {
		++cnt;
		aux /= val;
	}

	this->number = new char[cnt + 1];

	cnt = 0;
	if (nr == 0) {
		this->number[cnt++] = '0';
	}
	else {
		while (nr) {
			int aux = nr % val;
			if (aux >= 10)
				this->number[cnt++] = CharLetter(aux);
			else
				this->number[cnt++] = aux + '0';
			nr /= val;
		}
	}

	this->number[cnt] = '\0';  
	inverseaza_sir(this->number, cnt);
}
void Number::Print()
{
	std::cout << this->number <<std::endl;
}
int Number::GetDigitsCount()
{
	int c = 0;
	while (this->number[c]!=0)
		++c;
	return c;
}
int Number::GetBase()
{
	return this->base;
}
