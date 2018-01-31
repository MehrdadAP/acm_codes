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

struct node
{
	int data;
	node* left;
	node* right;
	node()
	{
		left=NULL;
		right=NULL;
	}
};

int a[MAX];
void read(node* root)
{
	int rootData=INF;
	int left,right;
	char ch;
	while (scanf("%c",&ch))
		if (ch=='(')
			break;
//	scanf("%c",&ch);//parante baz
	scanf("%d",&rootData);
	if (rootData==INF)
	{
		while (scanf("%c",&ch))
		if (ch==')')
			break;
		//scanf("%c",&ch);
		return ;
	}
	root=new node;
	root->data=rootData;
	read(root->left);
	read(root->right);
	while (scanf("%c",&ch))
		if (ch==')')
			break;
	//scanf("%c",&ch);//parantez Baste
	return;
	
}

int I;

int main ()
{
	int tc;
	int sum;
	char ch;
	while (cin>>I)
	{
		node* root=new node;
		for (int i=0;i<MAX;i++)
			a[i]=0;
		//scanf("%c",&ch);
		read(root);
		if (1)
			printf("yes\n");
		else
			printf("no\n");
	}
	
	return 0;

}
