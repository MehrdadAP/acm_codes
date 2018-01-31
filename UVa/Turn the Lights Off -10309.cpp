									/*ba yade oo */
/*
AC Code
brute force on first row and other rows have on choice !

more proof:
Theory:
* The minimal solution consists of a sequence of moves.
* Think of these moves as a series of XOR operations .. (m1 XOR m2 XOR m3 ...) = BOARD_CLEAR
* The usual associativity and XOR-the-same-thing-cancels-out properties
* still apply.
* So no two move should be on the same cell otherwise their effects
* cancel each other out.
* Due to associativity, we can apply moves from the sequence
* in any order and still be able to get the board cleared.
*
* We exploit associativity here by finding the correct moves
* starting from the top most to bottom most row.
* We brute force on the first row by considering all 2^10=1024 ways of switching.
* And one of these ways must be part of the minimal solution.
* The second row of the minimal solution must then clear any remaining
* lighted cells in the first row. 
And so on ... (the rest figure out yourself)

One trick to solving such problems is to think of how the final solution might be and how you could reach there...

*/


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
#define MAX 16
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;
#define inRange(x,y) ( x>=0 && x<10 && y>=0 && y<10)

bool off[MAX][MAX],YES;
bool tmp[10][10];

int dx[]={1,0,0,-1};
int dy[]={0,+1,-1,0};
int ans;

void switchAdj(int x,int y,bool flag)
{

	for (int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];

		if (inRange(xx,yy)){
			if (flag) tmp[xx][yy]=!tmp[xx][yy];
			else off[xx][yy]=!off[xx][yy];
		}
	}
}

void check(int cnt)
{

	for (int i=0;i<10;i++)
		for (int j=0;j<10;j++)
			tmp[i][j]=off[i][j];
	
	for (int i=1;i<10;i++)
		for (int j=0;j<10;j++)
		{
			if (tmp[i-1][j]==false)
			{
				tmp[i][j]=!tmp[i][j];
				switchAdj(i,j,true);
				cnt++;
				if (cnt>100)
					return;
			}
		}

	bool allOff=true;
	for (int j=0;j<10 && allOff;j++)
		if (tmp[9][j]==false)allOff=false;
	
	if (allOff)
		ans=min(ans,cnt);
}


void BTonFirstRow(int j,int cnt)
{
	if (j==10){check(cnt);return;}

	BTonFirstRow(j+1,cnt);

	switchAdj(0,j,false);
	off[0][j]=!off[0][j];
	BTonFirstRow(j+1,cnt+1);

	//back to init val
	switchAdj(0,j,false);
	off[0][j]=!off[0][j];
	
}

int main ()
{

	char name[1000];
	char ch;
	while (gets(name),strcmp(name,"end")!=0)
	{
		char line[20];
		for (int i=0;i<10;i++)
		{
			gets(line);
			for (int j=0;j<10;j++){
				if (line[j]=='#')off[i][j]=true;
				else off[i][j]=false;
			}
		}
		ans=INF;
		BTonFirstRow(0,0);
		if (ans==INF || ans>100)ans=-1;		
		printf("%s %d\n",name,ans);

	}

	return 0;
}
