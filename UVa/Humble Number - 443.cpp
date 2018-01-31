//Humble Number 
//By Heap Data Structure
//Time : O(nlgn)
//By Mehrdad Arabpour


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
#define INF 92233720368547
//#define MAX 5900*4
#define MAX 5850

#define Left(i) (2*i)
#define Right(i) (2*i+1)
#define Parent(i) ((int)(i/2))

//int *list;
long long int list[MAX*15];
int heapSize;

void MinHeapify(int i)
{
	int l=Left(i);
	int r=Right(i);
	int large;
	if (l<=heapSize && list[l]<list[i])
		large=l;
	else
		large=i;
	if (r<=heapSize && list[r]<list[large])
		large=r;
	if (large!=i)
	{
		swap(list[large],list[i]);
		MinHeapify(large);
	}
}

int ExtractMin()
{
	long long int temp=list[1];
	list[1]=list[heapSize];
	heapSize--;
	MinHeapify(1);
	return temp;
}

void HeapIncreasKey(int i,long long int key)
{
	list[i]=key;
	while (i>1 && list[i]<list[Parent(i)])
	{
		swap(list[i],list[Parent(i)]);
		i=Parent(i);
	}
}

void MinHeapInsert(long long int key)
{
	heapSize++;
	long long int temp;
	temp=INF;
	list[heapSize]=temp;
	HeapIncreasKey(heapSize,key);
}

 long int a[MAX];
int main ()
{
	int endA=1;
	long long int temp;
	int prime[4]={2,3,5,7};
	int n;
	//list=new int[MAX*100];
	heapSize=0;
	MinHeapInsert(1);
	bool flag=true;
	while(endA!=MAX)
	{
		for (int j=0;j<4 && flag;j++)
		{
			temp=list[1]*prime[j];
			if (temp>5000000000)
				flag=false;
			else
				MinHeapInsert(temp);
		}
		temp=ExtractMin();
		if (temp==a[endA-1])
		{
			while ((temp=ExtractMin())==a[endA-1]);
			MinHeapInsert(temp);
		}
		else
			a[endA++]=temp;
	}
	char* str;
	while (scanf("%d",&n),n!=0)
	{
		if (n%100==12 || n%100==11 || n%100==13 )
			str="th";
		else if (n%10==1)
			str="st";
		else if (n%10==2)
			str="nd";
		else if (n%10==3)
			str="rd";
		else
			str="th";
		printf("The %d%s humble number is %d.\n",n,str,a[n]);
	}
	return 0;

}
