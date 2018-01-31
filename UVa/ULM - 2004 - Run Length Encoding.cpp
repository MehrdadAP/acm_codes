#include <iostream>
#include <string>

using namespace std;

#define MAX 100000

int main ()
{
	char line[MAX];
	while (cin.getline(line,MAX))
	{
		int len=strlen(line);
		for (int i=0;i<len;i++)
		{
			int cnt=1;
			while (i<len-1 && cnt<9 && line[i]==line[i+1])
			{
				i++;
				cnt++;
			}
			if (cnt!=1)
			{
				printf("%d%c",cnt,line[i]);
			}
			else
			{
					printf("1");		
					while (i<len-1 && line[i]!=line[i+1])
					{
						if (line[i]=='1')
							printf("11");
						else
							printf("%c",line[i]);
						i++;
					}
					if (!(i!=len-1 && line[i]==line[i+1]))
						if (line[i]=='1')
							printf("11");
						else
							printf("%c",line[i]);
					printf("1");
					if (i!=len-1)
						i--;
			}
		}
		printf("\n");
	}
	return 0;
}