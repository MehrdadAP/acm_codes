/*ba yade oo */

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
#define INF 0x7FFFFFFF
#define MAX 1000002

int Hnumbers[MAX/100];



int BinSearch(int first,int last,int key)
{
	int mid=(first+last)/2;
	if (Hnumbers[mid]==key)
		return mid;
	if (first<=last)
		if (key<Hnumbers[first])
			return first;
		else
			return last;

	if (key<Hnumbers[mid])
		return BinSearch(first,mid-1,key);
	else
		return BinSearch(mid+1,last,key);
}
int main ()
{

	int ans=0;
	int cnt=0;
	Hnumbers[1]=0;
	for (int i=1;Hnumbers[i]<MAX;i++)
		Hnumbers[cnt++]=
	cout<<cnt;

	int n;
	while (scanf("%d",&n),n!=0)
		printf("%d\n",BinSearch(1,cnt,n));

	return 0;

}
