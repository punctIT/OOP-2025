#include <iostream>
#include "Math.h"

using namespace std;

int main() {
	Math mate;
	cout << mate.Add(10, 10) << endl;
	cout << mate.Add(10, 10,12) << endl;
	cout << mate.Add(10.3, 10.5) << endl;
	cout << mate.Add(10.2, 10.3,12.5) << endl;
	cout << mate.Mul(10, 10) << endl;
	cout << mate.Mul(10, 10,2) << endl;
	cout << mate.Mul(10.2, 10.3) << endl;
	cout << mate.Mul(10.2, 10.3,4.3) << endl;
	cout << mate.Add(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
	char *s= mate.Add("ceva", nullptr);
	if (s != nullptr)
		cout << s << endl;
	char *s2 = mate.Add("10070", "1234");
	if (s2 != nullptr)
		cout << s2 << endl;
	
}