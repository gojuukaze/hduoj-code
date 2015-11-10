#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int map[10][10];
int n,m;

int zx,zy;
bool f[10][10];
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
bool ok;
int dfs(int x,int y,int t)
{
	int i,j;
	if(x==zx && y==zy)
	{
		if(t==0)
			ok=1;
		return 0;
	}
	if(t==0)
		return 0;
	f[x][y]=1;
	for (i=0;i<4;i++)
	{
		int tx=x+xx[i];
		int ty=y+yy[i];
		if(tx>=0 && tx<n && ty>=0 && ty<m)
		{
			if(f[tx][ty]==0 && map[tx][ty]!=1)
			{
				int tt=abs(zx-tx)+abs(zy-ty);
				if(tt>(t-1))
					continue;
				if((t-1-tt)&1)
					continue;
				dfs(tx,ty,t-1);
				if(ok==1)
					return 0;
				f[tx][ty]=0;
			}
		}
	}
	return 0;
}

int main()
{

	int i,t,j;
	char c;
	while(~scanf("%d%d%d",&n,&m,&t))
	{
		if(n==m && m==t &&n==0)
			return 0;
		getchar();
		int qx,qy;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%c",&c);
				if(c=='X')
					map[i][j]=1;
				else
				{
					map[i][j]=0;
					if(c=='S')
					{
						qx=i;qy=j;
					}
					else if(c=='D')
					{zx=i;zy=j;}
				}
			}
			getchar();
		}

		ok=0;
		memset(f,0,sizeof(f));
		dfs(qx,qy,t);
		if(ok)
			printf("YES\n");
		else
			printf("NO\n");




	}
	return 0;
}
