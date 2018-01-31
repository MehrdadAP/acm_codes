#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX 999

int main()
{
	int temp;
	for (int i=0;i<MAX;i++)
	{
		for (int j=0;j<MAX;j++)
		{
			temp=rand()%10;
			printf("%d ",temp);
		}
		printf("\n");
	}
	return 0;

}