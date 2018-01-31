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
character a[28];
bool comp(character x,character y)
{
	if (x.cnt>y.cnt)
		return true;
	else
		if(x.cnt==y.cnt)
			if(x.ch<y.ch)
				return true;
			else 
				return false;
		else 
			return false;
}

char toUpper(char ch)
{
	if (ch>='a' && ch<='z')
		return (ch-('a'-'A'));
	else
		return ch;
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
		int len=strlen(line);
		for (int i=0;i<len;i++)
		{
			if (inRange(line[i]))
			{
				ch=toUpper(line[i]);
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

