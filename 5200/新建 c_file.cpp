#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

struct tree
{
	int hight;
	int no;
}h[50005];

struct cmp1
{
	bool operator() (tree a,tree b)
	{
		return a.hight<b.hight;
	}
};
struct Q
{
	int no;
	int date;
}q[50005];

struct cmp2
{
	bool operator() (Q a,Q b)
	{
		return a.date<b.date;
	}
};

struct cmp3
{
	bool operator() (Q a,Q b)
	{
		return a.no<b.no;
	}
};

bool f[50005];

int main()
{
	int m,n;
	int i,j;
	int cnt;
	int max;
	while(~scanf("%d%d",&n,&m))
	{
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&h[i].hight);
			max=max>h[i].hight?max:h[i].hight;
			h[i].no=i;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&q[i].date);
			q[i].no=i;
		}
		sort(h,h+n,cmp1());
		sort(q,q+m,cmp2());
		memset(f,1,sizeof(f));
		cnt=1;
		int cong=0;
		for(i=0;i<m;i++)
		{
			
			
			if(q[i].date>=max)
			{
				q[i].date=0;
				continue;
			}
		
			for(j=cong;h[j].hight<=q[i].date;j++)
			{
				
				int t=h[j].no;
				f[t]=0;

				if( t-1>=0 && t+1<n )
				{
					if( f[t-1]==1 && f[t+1]==1 )
						cnt++;	
					else if(f[t-1]==0 && f[t+1]==0)
						cnt--;
				}
				else
				{
					if(t-1<0)
					{
						if(f[t+1]==0)
							cnt--;
					}
					else
					{
						if(f[t-1]==0)
							cnt--;
					}
				}
			}
			cong=j;
			q[i].date=cnt;
		
		}
		sort(q,q+m,cmp3());
		for(i=0;i<m;i++)
			printf("%d\n",q[i].date);
	}
	return 0;
}