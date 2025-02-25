#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;


void sortare_cuvinte(char cuv[100][100],int nr)
{
	int c = 0;
	while (true)
	{
		for (int i = 0; i < nr-1; i++)
		{
			if (strlen(cuv[i]) < strlen(cuv[i + 1]))
			{
				c++;
				swap(cuv[i], cuv[i + 1]);
			}
		}
		if (c == 0)
			break;
		c = 0;
	}
	
}

int main()
{
	char s[100],cuvinte[100][100],aux[100];
	scanf_s("%[^\n]", s, (unsigned)_countof(s));
	int i = 0,c=0,nr=0;
	while (s[i])
	{
		if (s[i] == ' '||s[i]==0)
		{
			aux[c] = 0;
			strcpy_s(cuvinte[nr++], aux);
			c = 0;
		}
		else {
			aux[c++] = s[i];
		}
		++i;
	}

	aux[c] = 0;
	strcpy_s(cuvinte[nr++], aux);
	c = 0;
	sortare_cuvinte(cuvinte, nr);
	for (int i = 0; i < nr; i++)
		printf("%s\n", cuvinte[i]);

	
	
}