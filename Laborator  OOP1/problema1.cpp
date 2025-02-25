#include <iostream>
#include <stdio.h>

using namespace std;



int main()
{
	FILE* fisier;
	if (fopen_s(&fisier, "in.txt", "r") != 0){
		printf("eroare");
	}
	else {
		
		char s[100];
		while (fgets(s, 200, fisier))
		{
			
		}
	}
	
}