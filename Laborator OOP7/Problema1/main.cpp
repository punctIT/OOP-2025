#include <iostream>

using namespace std;

float operator"" _Kelvin(const char* x) {
	int nr = 0, c = 0;
	while (x[c])
	{
		nr = nr * 10 + x[c] - '0';
		++c;
	}
	return float(nr - 273.15);
}
float operator"" _Fahrenheit(const char* x) {
	int nr = 0, c = 0;
	while (x[c])
	{
		nr = nr * 10 + x[c] - '0';
		++c;
	}
	return float((nr - 32)/1.8);
}
int main() {
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	cout << a << endl;
	cout << b << endl;
	return 0;
}