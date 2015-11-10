#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int a[30];
int ji[10][10];
int n,m,k;

int xx[]={-1,0};
int yy[]={0,-1};
bool dfs(int i,int x,int y,int num)
{    

	int j;
	if(x!=1 && y==1)
	{
		int biao=(n-x+1)*m;
        biao=biao/2+(biao%2==0?0:1);
        for(j=1;j<=k;j++)
        {
            if(a[j]>biao)
            {
                a[j]++;
                return false;
            }
        }
	}
    if(a[i]!=0)
    {
    
        for(j=0;j<2;j++)
        {
            if(ji[x+xx[j]][y+yy[j]]==i)
                return false;
        }
        ji[x][y]=i;
        a[i]--;
        num++;
        if(num==n*m)
            return true;

        int ty,tx;
        for(j=1;j<=k;j++)
        {
            if(j!=i)
            {
                if(y==m)
                {
                    ty=1;
                    tx=x+1;
                }
                else
                {
                    tx=x;
                    ty=y+1;
                }
                if(dfs(j,tx,ty,num))
                    return true;
            }
        }
        a[i]++;
    }
    return false;
}
int main()
{
    int t,i,j;
    bool no=0;
    int c=0;
    scanf("%d",&t);
    while(t--)
    {
        c++;
        no=0;
        scanf("%d%d%d",&n,&m,&k);
        int biao=m*n/2+(n*m%2==0?0:1);
        for(i=1;i<=k;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>biao)
                no=1;
        }
        if(no)
            printf("Case #%d:\nNO\n",c);
        else
        {
            printf("Case #%d:\nYES\n",c);
            //memset(ji,0,sizeof(ji));
            for(i=1;i<=k;i++)
            {
                if(dfs(i,1,1,0))
                    break;
            }
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    printf("%d",ji[i][j]);
                    if(j!=m)
                        printf(" ");
                }
                printf("\n");
            }

        }
    }
    return 0;
}