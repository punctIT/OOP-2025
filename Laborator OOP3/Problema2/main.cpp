#include "Canvas.h"
#include <iostream>
using namespace std;


int main() {
	int opt;
	Canvas c(50, 50);
	while (true)
	{
		system("cls");
		cout << "0 - exit" << endl;
		cout << "1 - Print canvas" << endl;
		cout << "2 - drawRect" << endl;
		cout << "3-draw line" << endl;
		cout << "4-draw circle" << endl;
		cout << "5 fill circle" << endl;
		cout << "6 fill rect" << endl;
		cout << "7 clear" << endl;
		cin >> opt;
		if (opt == 0)
			break;
		if (opt == 1) {
			system("cls");
			c.Print();
			cout << "type any NUMBER to continue" << endl;
			int a; cin >> a;
		}
		if (opt == 2)
		{
			system("cls");
			cout << "left , top , right ,bottm, ch" << endl;
			int a, b, c1, d;
			char ch;
			cin >> a >> b >> c1 >> d >> ch;
			c.DrawRect(a, b, c1, d, ch);
		}
		if (opt == 3) {
			system("cls");
			cout << "x1 y1 x2 y2 ch" << endl;
			int x1, x2, y1, y2;
			char ch;
			cin >> x1 >> y1 >> x2 >> y2 >> ch;
			c.DrawLine(x1, y1, x2, y2, ch);
		}
		if (opt == 4)
		{
			system("cls");
			int x, y, ray;
			char ch;
			cout << " x, y ray ch" << endl;
			cin >> x >> y >> ray >> ch;
			c.DrawCircle(x, y, ray, ch);
		}
		if (opt == 5) {
			system("cls");
			int x, y, ray;
			char ch;
			cout << " x, y ray ch" << endl;
			cin >> x >> y >> ray >> ch;
			c.FillCircle(x, y, ray, ch);
		}
		if (opt == 6)
		{
			system("cls");
			cout << "left , top , right ,bottm, ch" << endl;
			int a, b, c1, d;
			char ch;
			cin >> a >> b >> c1 >> d >> ch;
			c.FillRect(a, b, c1, d, ch);

		}
		if (opt == 7)
		{
			system("cls");
			c.Clear();
		}
	}
	

}