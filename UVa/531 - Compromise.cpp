//Compromise
//By Mehrdad Arabpour
//given tow paragraph terminated by a #
//output is the common words
//a simple string hanlding needed
//attention :no space after last word of each test case



#include <iostream>
#include <stdio.h>
#include <string>
 using namespace std;
#define MAX 100
string a[MAX],b[MAX];
int p[MAX][MAX];
int t[MAX+1][MAX+1];

 void init_t(int n)
 {
		for (int i=0;i<=n;i++) 
		{
			t[i][0]=0;
			t[0][i]=0;
		}
		for (int i=0;i<=n;i++)
			for (int j=0;j<=n;j++)
				p[i][j]=0;
 }
 int cnt,res;
 void print_path(int n1,int n2)
 {
	 if (n1==0 || n2==0)
		return ;
	 else
	 {
		 if (p[n1][n2]==1)
		 {
			 print_path(n1-1,n2-1);
			 cnt++;
			 if (cnt==res)
				cout<<a[n1];
			 else
				 cout<<a[n1]<<" ";
			 
		 }
		 else if (p[n1][n2]==2)
		 {
			 print_path(n1-1,n2);
		 }
		 else
		 {
			 print_path(n1,n2-1);
		 }
	 }
 }
 
 int main ()
 {
	 int n1,n2;
	 //
	 n1=0;
	 while (cin>>a[++n1])
	 {
		cnt=0;
		n2=0;
		while (a[n1]!="#") 
		{
			cin>>a[++n1];
		}
//		cout<<a[3]<<endl;
		do 
		{
			cin>>b[++n2];
		}while (b[n2]!="#");

//		cout<<b[3]<<endl;
		//printf("Inputs : %d , %d\n",n1,n2);
		 n1--;n2--;
		 init_t(max(n1,n2));

		 for (int i=1;i<=n1;i++)
		 {
			 for (int j=1;j<=n2;j++)
			 {
				 if (a[i]==b[j])
				 {
					 t[i][j]=t[i-1][j-1]+1;
					 p[i][j]=1;
				 }
				 else if (t[i-1][j]>=t[i][j-1])
				 {
					 t[i][j]=t[i-1][j];
					 p[i][j]=2;
				 }
				 else
				 {
					 t[i][j]=t[i][j-1];
					 p[i][j]=3;
				 }
			 }
		 }

		//cout<<t[n1][n2]<<endl;
		res=t[n1][n2];
		print_path(n1,n2);
		cout<<endl;
		n1=0;
	 }
	//system("pause");
	 return 0;
 }