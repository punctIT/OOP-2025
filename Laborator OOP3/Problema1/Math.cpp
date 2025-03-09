#include "Math.h"
#include <cstdarg>
#include <cstring>

int Math::Add(int a, int b) {
	return a + b;
}
int Math::Add(int a, int b,int c) {
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * c * b;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...)
{
	va_list va;
	int sum = 0;
	va_start(va, count);
	for (int i = 0; i < count; i++){
		sum += va_arg(va, int);
	}
	va_end(va);
	return sum;
}
char * Math:: Add(const char* a, const char* b) {
	if (a == nullptr || b == nullptr)
		return nullptr;
	int la = strlen(a);
	int lb = strlen(b);

	int max = la;
	if (lb > max)
		max = lb;
	char* result = new char[max + 1];
	la--;
	for (int i = max-1;la >=0 && i >= 0; i--,la--){
		result[i] = a[la];
	}
	lb--;
	int rest = 0;
	for (int i = max - 1; lb >= 0 && i >= 0; i--, lb--) {
		if (result[i] >= '0' && result[i] <= '9')
		{
			int nr = result[i] - '0' + b[lb] - '0';
			if (nr + rest >= 10)
			{
				result[i] = (nr + rest) % 10 + '0';
				rest = (nr + rest) % 10;
			}
			else {
				result[i] = (nr + rest) % 10 + '0';
				rest = 0;
			}
				
		}
		else {
			result[i] = b[lb];
			rest = 0;
		}
	}

	result[max] = 0;
	return result;
}