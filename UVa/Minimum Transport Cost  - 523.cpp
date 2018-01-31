#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <sstream>

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define MAX 200
#define INF 2147483647
#define LINF 100000


int a[MAX][MAX];
int tax[MAX];
int parent[MAX][MAX];
void printArr(int arr[][MAX],int n)
{
	cout<<endl;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void printPath(int i,int j)
{
	if (parent[i][j]==-1)
	{
		//cout<<i+1;
		return ;
	}
	printPath(i,parent[i][j]);
	printf("-->%d",j+1);
}
int main ()
{
	string strLine;
	istringstream myStream;
	int tc;
	getline(cin,strLine);
	myStream.str(strLine);
	myStream>>tc;
	int n=0;
	char* line=new char[MAX];
	int val;
	getline(cin,strLine);
	while (tc--)
	{
		
		getline(cin,strLine);
		myStream.clear();
		myStream.str(strLine);
		n=count(strLine.begin(),strLine.end(),' ')+1;
		for (int i=0;i<n;i++)
		{
			
			for (int j=0;j<n;j++)
			{
				myStream>>val;
				if (i==j)
					parent[i][j]=-1;
				else 
					parent[i][j]=i;
				if (val==-1)
				{
					a[i][j]=LINF;
					parent[i][j]=-1;
				}
				else
				{
					a[i][j]=val;
				}
			}
			if (i==n-1)
				break;
			getline(cin,strLine);
			myStream.clear();
			myStream.str(strLine);
		}
		
		getline(cin,strLine);
		myStream.clear();
		myStream.str(strLine);

		for (int i=0;i<n;i++)
			myStream>>tax[i];
		//printArr(n);
		//floyd
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
				{
					if (a[i][j]>a[i][k]+a[k][j]+tax[k])
					{
						a[i][j]=a[i][k]+a[k][j]+tax[k];
						parent[i][j]=parent[k][j];
					}
				}
		//printArr(parent,n);
		int s,e;
		getline(cin,strLine);
		myStream.clear();
		myStream.str(strLine);
		while (strLine!="")
		{	
			myStream>>s>>e;
			printf("From %d to %d :\nPath: ",s,e);
			
			cout<<s;
			printPath(s-1,e-1);
			cout<<endl;
			
			printf("Total cost : %d\n",a[s-1][e-1]);
			
			
			getline(cin,strLine);
			myStream.clear();
			myStream.str(strLine);
			if (strLine!="")
				printf("\n");
		}
		if (tc!=0)
			printf("\n");
		
		
	}

	return 0;

}
