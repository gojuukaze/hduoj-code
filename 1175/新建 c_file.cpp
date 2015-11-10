#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int map[1010][1000];
int n,m;

int zx,zy;
bool f[1010][1000];
int xx[]={1,0,-1,0};
int yy[]={0,-1,0,1};
bool ok;
int biao;
bool fir;
bool check(int x,int y)
{
	if(x>=0 &&x<n && y>=0 && y<m)
		return true;
	else
		return false;
}
int dfs(int x,int y,int t,int fan)
{
	int i,j;
	if(t==0)
	{
		int nn;
		if(fan<=1)
			nn=m;
		else nn=n;
		int tx=x;
		int ty=y;
		for(i=0;i<n;i++)
		{
			tx+=xx[fan];
			ty+=yy[fan];
			if(check(tx,ty))
			{
				if(map[tx][ty]!=0)
				{
				
					if(tx==zx && ty==zy )
					{
						ok=1;return 0;
					}
					else
						return 0;
				}	
			//	f[tx][ty][fan]=1;
			}
			else return 0;

		}
		return 0;
	}

	f[x][y]=1;
	for (i=0;i<4;i++)
	{
		int tx=x+xx[i];
		int ty=y+yy[i];
		if(tx>=0 && tx<n && ty>=0 && ty<m)
		{
			if(f[tx][ty]==0 )
			{
				
				if(map[tx][ty]==0 )
				{
					f[tx][ty]=1;
					if(fir)
					{
					//	fan=i;
					//	t--;
						fir=0;
						dfs(tx,ty,t-1,i);
						
						f[tx][ty]=0;
						fir=1;
					}
					else if(fan!=i)
					{
						dfs(tx,ty,t-1,i);
					}
					else 
						dfs(tx,ty,t,i);

					f[tx][ty]=0;
				}
				else if(tx==zx && ty==zy)
				{
					ok=1;
					return 0;
				}
				if(ok==1)
						return 0;
			}
		}
	}
	return 0;
}

int main()
{

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,t,j,q;
	int the=0;
	while(~scanf("%d%d",&n,&m))
	{
		if(n==m &&n==0)
			return 0;
		int qx,qy;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
			qx--;qy--;zx--;zy--;
			ok=0;
			if(map[qx][qy]==map[zx][zy] &&map[zx][zy]!=0 && (zx!=qx || zy!=qy) )
			{
			
				fir=1;
				biao=map[qx][qy];
				memset(f,0,sizeof(f));
				dfs(qx,qy,3,1);
			}
		
			
			if(ok)
				printf("YES\n");
			else
				printf("NO\n");
		}




	}
	return 0;
}
