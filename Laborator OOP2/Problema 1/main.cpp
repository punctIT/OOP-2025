#include "NumberList.h"
#include <iostream>

using namespace std;

int main()
{
	int option = 0;
	NumberList list;
	list.Init();
	while (true)
	{
		cout << "1-add" << endl << "2-sort"<<endl << "3-print" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "introdu o valuare:";
			int x;
			cin >> x;
			list.Add(x);
			break;
		case 2:
			list.Sort();
			break;
		case 3:
			list.Print();
			break;
		default:
			return 0;
			break;
		}
	}
}