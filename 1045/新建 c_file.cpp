#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int map[10][10];
int f[10][10];
int n;
int ccount;

int biaoji(int x,int y)
{
	int i,j;
	map[x][y]++;
	for(i=x,j=y+1;j<n;j++)
	{
		if(map[i][j]==1)
			break;
		else
			f[i][j]++;
	}
	for(i=x,j=y-1;j>=0;j--)
	{
		if(map[i][j]==1)
			break;
		else
			f[i][j]++;
	}
	for(i=x+1,j=y;i<n;i++)
	{
		if(map[i][j]==1)
			break;
		else
			f[i][j]++;
	}
	for(i=x-1,j=y;i>=0;i--)
	{
		if(map[i][j]==1)
			break;
		else
			f[i][j]++;
	}
	return 0;
}

int huisu(int x,int y)
{
	int i,j;
	map[x][y]--;
	for(i=x,j=y+1;j<n;j++)
	{
		if(map[i][j]==1)
			break;
		else
			f[i][j]--;
	}
	for(i=x,j=y-1;j>=0;j--)
	{
		if(map[i][j]==1)
			break;
		else
			f[i][j]--;
	}
	for(i=x+1,j=y;i<n;i++)
	{
		if(map[i][j]==1)
			break;
		else
			f[i][j]--;
	}
	for(i=x-1,j=y;i>=0;i--)
	{
		if(map[i][j]==1)
			break;
		else
			f[i][j]--;
	}
	return 0;
}

int mmax;

int dfs(int x,int y)
{
	int i,j;
	biaoji(x,y);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(map[i][j]==0 && f[i][j]==0)
			{
				ccount++;
				dfs(i,j);
				ccount--;
				huisu(i,j);
			}
		}
	}
	mmax=mmax>ccount?mmax:ccount;
	return 0;
}

int main()
{

	int i,t,j;
	char c;
	while(~scanf("%d",&n))
	{
		if(n==0)
			return 0;
		getchar();

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%c",&c);
				if(c=='.')
					map[i][j]=0;
				else
				{
					map[i][j]=1;
				}
			}
			getchar();
		}

		memset(f,0,sizeof(f));
		bool one=0;
		mmax=0;
		ccount=0;
		for(i=0;i<n;i++)
		{
			one=0;
			for(j=0;j<n;j++)
			{
			
				if(map[i][j]==0)
				{
					one=1;
					ccount=1;
					dfs(i,j);
					huisu(i,j);
				}
				else
				{
					if(one)
						break;
				}
			}
		}
		printf("%d\n",mmax);





	}
	return 0;
}
