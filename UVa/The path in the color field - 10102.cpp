#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;
#define MAX 500
#define inRange(x,y,n) (x>=0 && y>=0 && x<n && y<n)

char a[MAX][MAX];
bool v[MAX][MAX];
int d[MAX][MAX];
int n;

void v_init(int n)
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			v[i][j]=false;
			d[i][j]=0;
		}
}
struct cell
{
	int x;int y;
};

int BFS(cell one)
{
	queue<cell> q;
	q.push(one);
	int cnt=0;
	//cout<<"umadam"<<endl;
	while (!q.empty())
	{	

		//cout<<"umadam"<<endl;
		int fx=q.front().x;
		int fy=q.front().y;
	//	cout<<fx<<" "<<fy<<endl;
		if (a[fx][fy]=='3')
		{
	//		cout<<"d : "<<d[fx][fy]<<endl;
			return d[fx][fy];
		}
		cell temp;
		if (inRange (fx-1,fy,n) && !v[fx-1][fy])
		{
			//cout<<"bala"<<endl;
			temp.x=fx-1;
			temp.y=fy;
			v[temp.x][temp.y]=true;
			d[temp.x][temp.y]=d[fx][fy]+1;
			q.push(temp);
		}
		if (inRange(fx,fy+1,n) && !v[fx][fy+1])
		{
			//cout<<"bala"<<endl;
			temp.x=fx;
			temp.y=fy+1;
			v[temp.x][temp.y]=true;
			d[temp.x][temp.y]=d[fx][fy]+1;
			q.push(temp);
			
		}
		
		if (inRange (fx,fy-1,n) && !v[fx][fy-1])
		{
			//cout<<"bala"<<endl;
			temp.x=fx;
			temp.y=fy-1;
			v[temp.x][temp.y]=true;
			d[temp.x][temp.y]=d[fx][fy]+1;
			q.push(temp);
		}

		if (inRange (fx+1,fy,n) && !v[fx+1][fy])
		{
			//cout<<"bala"<<endl;
			//cout<<"boogh";
			temp.x=fx+1;
			temp.y=fy;
			v[temp.x][temp.y]=true;
			d[temp.x][temp.y]=d[fx][fy]+1;
			q.push(temp);

		}
		q.pop();
	}

}

int main ()
{
	char ch;
	while (scanf("%d",&n)==1)
	{
		scanf("%c",&ch);
		for (int i=0;i<n;i++)
 			for (int j=0;j<n;j++)
				scanf("%c",&a[i][j]);
		int ans=-1;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				if (a[i][j]=='1')
				{
					v_init(n);
					cell one;
					one.x=i;one.y=j;
//					ans=BFS(one);
					ans=max(BFS(one),ans);
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}