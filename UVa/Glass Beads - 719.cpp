#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAX 10010

char c[MAX],c2[MAX*2];
int main ()
{
	int tc;
	int len;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%s",c);
		len=strlen(c);
		strcpy(c2,c);
		strcpy(c2+len,c);
		int minIndex=0;
		for (int start=1;start<len;start++)
		{ 
			if (strncmp(c2+start,c2+minIndex,len)<0)
				minIndex=start;
			
		}
		printf("%d\n",minIndex+1);
	}


	return 0;

}
