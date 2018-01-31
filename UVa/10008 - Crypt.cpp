#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>
#include <ctype.h>


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 1e8
#define MAX 100000
#define inRange(x) ((x<='z' && x>='a')|| (x<='Z' && x>='A'))

struct character
{
	char ch;
	int cnt;
};
character a[27];
bool comp(character a,character b)
{
	if (a.cnt>b.cnt)
		return true;
	else
		return false;
}
int main ()
{
	char line[MAX];
	for (int i=0;i<27;i++)
		a[i].cnt=0;

	int n;
	char ch;
	cin.getline(line,MAX);
	sscanf(line,"%d",&n);
	while (n--)
	{
		cin.getline(line,MAX);
		for (int i=0;i<strlen(line);i++)
		{
			if (inRange(line[i]))
			{
				ch=toupper(line[i]);
				int ind=ch-'A';
				a[ind].ch=ch;
				a[ind].cnt++;
			}
		}
	}
	sort(a,a+26,comp);
	for (int i=0;i<26;i++)
		if (a[i].cnt!=0)
			printf("%c %d\n",a[i].ch,a[i].cnt);
		
	//system("pause");
	return 0;

}

