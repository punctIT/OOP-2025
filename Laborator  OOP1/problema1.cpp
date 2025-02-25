#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
	FILE* fisier;
	int suma = 0;
	if (fopen_s(&fisier, "in.txt", "r") != 0) {
		printf("eroare");
	}
	else {

		char s[100];
		while (fgets(s, 100, fisier))
		{
			int numar = 0;
			int i = 0;
			while (s[i] != 0)
			{
				if(s[i]>47&&s[i]<='9')
					numar = numar * 10 + s[i] - 48;
				i++;
			}
			suma += numar;
		}
	}
	printf("%d ", suma);

}