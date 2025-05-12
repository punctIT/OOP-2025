#include <iostream>
#include <exception>
#include "Array.h"

using namespace std;

int compare(int a, int b) {
	return a < b;
}

int main() {
	Array<int> f = { 1122,23,3,4,5 };
	f.print();
	f.sort();
	f.print();
	f.push(10);
	Array<int> f2 = f;
	
	f2 += 2;
	f2.print();
	
	f2 -= 4;
	f2.print();
	try {
		f2 /= 0;
		cout << endl;
		f.print();
	}
	catch (exception& e) {
		cout<<e.what();
		cout << endl;
	}
	f2.pop(-1);
	f2.print();
	Array<string> g = { "unu ", "doi" , "Trei" };
	g.print();
	cout << endl;
	try {
		int a =g.Find("ana");
		cout << "pozitia este " << a << endl;
	}
	catch (exception& e) {
		cout << e.what();
		cout << endl;
	}
	cout << endl;
	try {
		cout << g[2] << endl;
	}
	catch (exception& e) {
		cout << e.what();
		cout << endl;
	}
	cout << endl;
	try {
		cout << g[-124];
	}
	catch (exception& e) {
		cout << e.what();
		cout << endl;
	}
}