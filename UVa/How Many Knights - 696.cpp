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
#define INF 1e8

int main ()
{
	int m,n,size;
	while (scanf("%d %d",&m,&n),m!=0 || n!=0)
	{
		size=m*n;
		if (m==1 || n==1)
			printf("%d knights may be placed on a %d row %d column board.\n",m*n,m,n);
		else if ((m==2 && n%2!=0) || ((n==2 && m%2!=0)))
			printf("%d knights may be placed on a %d row %d column board.\n",((m*n)/2)+1,m,n);
		else if (size>8)
			printf("%d knights may be placed on a %d row %d column board.\n",(size+1)/2,m,n);
		else if (size<=5)
			printf("%d knights may be placed on a %d row %d column board.\n",size,m,n);
		else if (size==6)
			printf("%d knights may be placed on a %d row %d column board.\n",4,m,n);
		
	}


	return 0;

}
