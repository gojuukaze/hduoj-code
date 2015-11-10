#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int a[1005];
bool f[1005];
int ji[1005];

int the;
int n,sum;
bool ok;

//bool shang;
int dfs(int x,int he)
{
	int i,j;
	if(he==sum)
	{
		ok=1;
	//	shang=1;
		for(i=0;i<the;i++)
		{	
			printf("%d",ji[i]);
			if(i!=the-1)
				printf("+");
		}
		printf("\n");
		return 0;
	}

//	shang=0;
//	int jj=-1;
	for(i=x+1;i<n;i++)
	{
		if(f[i]==0 && he+a[i]<=sum)
		{
			if(ji[the]==a[i])
				continue;
			f[i]=1;
			ji[the]=a[i];
			the++;
			dfs(i,he+a[i]);
			f[i]=0;
			the--;
		//	if(shang)
			//	jj=a[i];
		}

	}
	ji[the]=-1;

	return 0;
}

int main()
{

	int i,t,j;
	while(~scanf("%d%d",&sum,&n))
	{
		if(n==sum &&n==0)
			return 0;

		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);	
		}
		printf("Sums of %d:\n",sum);
		ok=0;
		int biao=-1;
		for(i=0;i<n;i++)
		{
			if(a[i]==biao)
				continue;
			memset(f,0,sizeof(f));
			the=0;
			ji[the]=a[i];
			the++;
			f[i]=1;
			dfs(i,a[i]);
			biao=a[i];
		}
		if(ok==0)
			printf("NONE\n");
	}
	return 0;
}
