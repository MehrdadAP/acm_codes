#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define MAX 102
class person
{
public:
	int id;
	int correct;
	int incorrect;
	int time;
	int problem[11];
	bool submision;
	bool operator<(const person other)
	{
		if (this->correct<other.correct)
			return true;
		if (this->correct>other.correct)
			return false;
		if (this->time<other.time)
			return true;
		if (this->time<other.time)
			return false;
		if (this->id>other.id)
			return true;
		else
			return false;
	};
	void reset()
	{
		correct=incorrect=time=0;
		submision=false;
		for (int i=0;i<11;++i)
			problem[i]=-1;
	}
	person()
	{
		//this->id=id;
		correct=incorrect=time=0;
		submision=false;
		for (int i=0;i<11;++i)
			problem[i]=-1;
	}
};



bool exist(int id,int cnt,int list[])
{
	for (int i=0;i<cnt;i++)
		if (list[i]==id)
			return true;
	return false;
}

int main ()
{
	char s[100];
	int tc;
	char tcChar[10];
	gets(tcChar);
	sscanf(tcChar,"%d",&tc);
	int id,prob,time;

	char state;
	int cnt=0;
	person acmer[MAX];
	for (int i=1;i<MAX;i++)
			acmer[i].id=i;
	gets(s);
	while (tc--)
	{
		for (int i=0;i<MAX;i++)
			acmer[i].reset();
		int list[MAX];
		cnt=0;
		while(1)
		{
			
			if (gets(s)==NULL || s[0]=='\0')
			{
				for (int i=0;i<cnt-1;i++)
					for (int j=i+1;j<cnt;j++)
						if (acmer[list[i]]<acmer[list[j]])
							swap(list[i],list[j]);		
				for (int i=0;i<cnt;i++)
				{
					printf("%d %d %d\n",acmer[list[i]].id,acmer[list[i]].correct,acmer[list[i]].time);
				}
				if (tc!=0)
					printf("\n");
				break;
			}
			sscanf(s,"%d %d %d %c",&id,&prob,&time,&state);
			if (state=='C')
			{
				if (acmer[id].problem[prob]==-1)
					acmer[id].time+=time;
				else if (acmer[id].problem[prob]==0)
					continue;
				else
					acmer[id].time+=acmer[id].problem[prob]*20+time;	
				acmer[id].problem[prob]=0;
				acmer[id].correct++;
				acmer[id].submision=true;
				if (!exist(id,cnt,list))
				{
					list[cnt++]=id;
				}
			}
			else if (state=='I')
			{
				if (acmer[id].problem[prob]==-1)
					acmer[id].problem[prob]=1;
				else if (acmer[id].problem[prob]==0)
					continue;
				else
					acmer[id].problem[prob]++;
				acmer[id].submision=true;
				if (!exist(id,cnt,list))
				{
					list[cnt++]=id;
				}
			}
			else
			{
				acmer[id].submision=true;
				if (!exist(id,cnt,list))
				{
					list[cnt++]=id;
				}
			}
		}
	}
	return 0;
}