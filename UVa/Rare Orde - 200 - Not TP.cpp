#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>
#include <queue>

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 1e8

#define MAX 5000

char ch[MAX][22];

bool visited[30];
int main ()
{
	char line[22];
	int cnt=0;
	while (scanf("%s",ch[cnt++]),ch[cnt-1][0]!='#')
	{
		int len=strlen(ch[cnt-1]);
		for (int i=len;i<22;i++)
			ch[cnt-1][i]='a';
	}
	cnt--;
	for (int i=0;i<30;i++)
		visited[i]=false;
	for (int i=0;i<22;i++)
	{
		for (int j=0;j<cnt;j++)
		{
			if (ch[j][i]>='A' && ch[j][i]<='Z')
				if (visited[ch[j][i]-'A']==false)
				{
					printf("%c",ch[j][i]);
					visited[ch[j][i]-'A']=true;
				}
		}
	}
	printf("\n");
	//system("pause");
	return 0;

}
