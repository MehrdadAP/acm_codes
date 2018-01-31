																/*ba yade oo*/
//Mehrdad AP


#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std ; 
 
#define  MAXN  100009
#define  MAXLG 100
 
char A[MAXN]; 
struct entry { 
    int  nr [2], p; 
} L[MAXN]; 
int P[MAXLG][MAXN],  N,  i, stp, cnt ; 
 
int cmp(struct  entry a , struct entry b) 
{ 
   return  a.nr[0]  ==  b.nr[0] ?  (a .nr[1] <  b.nr[1] ? 1  : 0 )  : (a.nr [0]  < b.nr[0 ] ?  1 : 0); 
} 


char* STRrev(char *B)
{
	int N=strlen(B);

	for (int i=0;i<N/2;i++)
		swap(B[i],B[N-i-1]);
	return B;
}
 
int lcp(int x, int y) 
{ 
    int  k,  ret = 0; 
    if  (x  == y) return  N - x; 

    for  (k  = stp -  1;  k >= 0 &&  x  < N && y  < N ;  k --)
         if  (P[k][x]  ==  P[k][y])
              x += 1  <<  k, y += 1 <<  k, ret+= 1 << k;
    return  ret;
}
 
void make_SA()
{
	for  (N  = strlen (A) , i = 0;  i <  N; i  ++) 
			 P[ 0][i] = A [i]  - '.'; 

	for  (stp = 1, cnt  = 1; cnt  >>  1 < N; stp++,  cnt <<= 1 ) 
	{ 
		for (i = 0;  i  < N; i ++ ) 
		{ 
			L[i].nr [0]  = P[stp  - 1 ][ i]; 
			L[i].nr [1]  = i + cnt <  N ? P[stp -  1][i + cnt]  : -1; 
			L[i].p  = i ; 
		} 
		sort(L, L +  N,  cmp); 
		for (i = 0;  i  < N; i ++ ) 
			P[stp][L[i ].p] = i  > 0  && L[ i]. nr[ 0] == L[i  -  1].nr[0]  &&  L[i].nr[1 ] ==  L[i - 1 ].nr[1] ? 
			P[stp][ L[i  - 1].p]  : i ;
	}
	//printf("step: %d\n",stp);

}
 
int main() 
{ 
	char B[MAXN],C[MAXN];
	int tc;
	cin>>tc;
	cin.ignore();
    while (tc--)
	{
		gets(C);

		N=strlen(C);
		A[0]=C[0];
		int cnt=1;
		for (int i=1;i<N;i++)
		{
			if (C[i]==C[i-1])continue;
			A[cnt++]=C[i];
		}
		A[cnt]='\0';
		//cout<<A<<endl;

		B[0]='.';
		B[1]='\0';
		//init
		strcat(B,STRrev(A));
		STRrev(A);
		strcat(A,B);
		//cout<<A<<endl;
		
		make_SA();		
		//print
		
		/*for (int i=0;i<N;i++)
			cout<<i<<" : "<<P[stp-1][i]<<endl;
*/

		//find palindrome
		int ans=0;
		int tmp;
		bool even=true;
		for (int i=0;i<N/2;i++)
		{
			//odd
			tmp=lcp(i,N-i-1);
			//cout<<i<<","<<N-i-1<<" "<<tmp<<endl;
			if (tmp>ans)
			{
				ans=tmp;
				even=false;
			}

			//even
			tmp=lcp(i,N-i);
			//cout<<i<<","<<N-i<<" "<<tmp<<endl;
			if (tmp>ans)
			{
				ans=tmp;
				even=true;
			}

		}
		
		int expols=0;
		if (even)
			expols=2*ans;
		else
			expols=2*ans-1;

		cout<<(expols+1)/2<<endl;
	}
    

    return 0; 
}
