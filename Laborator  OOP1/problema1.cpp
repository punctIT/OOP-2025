#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
	FILE* fisier;
	if (fopen_s(&fisier, "in.txt", "r") != 0) {
		printf("eroare");
	}
	
	else {

		char s[100];
		while (fgets(s, 100, fisier))
		{

			int c = 0, suma = 0;
			while (s[c] != 0)
			{	
				suma += s[c];
				cout << s << endl;
				++c;
			}
			suma -= (c * 48);
			cout << suma << " ";
		}
	}

}