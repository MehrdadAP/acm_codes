									/*ba yade oo */
//Mehrdad AP
//AC Code

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



using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define pow2(x) (x*x)
#define EPS 1e-7
#define INF 100000000
#define MAX 150
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

string mx[MAX],mini[MAX];

int main ()
{

	mx[2]="1";
	mx[3]="7";
	mx[4]="11";
	for (int i=5;i<110;i++){
		if (mx[i-3].size()>=mx[i-2].size())
			mx[i]="7"+mx[i-3];
		else mx[i]=mx[i-2]+"1";
	}

	mini[2]="1";
	mini[3]="7";
	mini[4]="4";
	mini[5]="2";
	mini[6]="6";
	mini[7]="8";
	mini[8]="10";
	
	mini[9]="18";
	mini[10]="22";
	mini[11]="20";
	mini[12]="28";
	mini[13]="68";
	mini[14]="88";
	
	for (int i=15;i<110;i++){
		if (mini[i-6].size()<mini[i-7].size())
			mini[i]=mini[i-6]+"0";
		else if (mini[i-6].size()==mini[i-7].size()){
			if (mini[i-6]<=mini[i-7])	mini[i]=mini[i-6]+"0";
			else						mini[i]=mini[i-7]+"8";
		}
		else	mini[i]=mini[i-7]+"8";
	}

	int N;
	int tc;
	cin>>tc;
	while (tc--){
		cin>>N;
		cout<<mini[N]<<" "<<mx[N]<<endl;
	}




	return 0;
}
