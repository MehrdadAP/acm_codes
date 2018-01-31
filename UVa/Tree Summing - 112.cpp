// Problem    : Tree Summing
// Category   : Recursive
// Complexity : O(n)
// Author     : Mehrdad Arabpour

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 0x0FFFFFFF
#define MAX 100000

int I;

bool flag;
int read(int sum)
{
	int root=INF;
	char ch;
	while (scanf("%c",&ch))
		if (ch=='(')
			break;
//	scanf("%c",&ch);//parante baz
	scanf("%d",&root);
	if (root==INF)
	{
		while (scanf("%c",&ch))
		if (ch==')')
			break;
		/*if (sum==I)
			flag=true;*/
		return -1;
	}
	int left=read(sum+root);
	int right=read(sum+root);
	if (left==-1 && right==-1)
		if (sum+root==I)
			flag=true;
	while (scanf("%c",&ch))
		if (ch==')')
			break;
	//scanf("%c",&ch);//parantez Baste
	return 1;
	
}

int main ()
{
	while (scanf("%d",&I)==1)
	{
		flag=false;
		read(0);
		if (flag)
			puts("yes");
		else
			puts("no");
	}
	
	return 0;

}
