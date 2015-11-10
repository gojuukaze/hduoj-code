#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

double f(double aa)
{
	if(aa<0)
		aa=-aa;
	return aa;
}

struct tx
{
	int t,x;
/*	tx operator <(S x,S y)
    {
        return x.len<y.len;
    }*/
}a[10005];

bool cmp(tx a,tx b)
{
	return a.t<b.t;
}
int main()
{
	int n,m;
	scanf("%d",&n);
	int t=1;
	while(n--)
	{
		scanf("%d",&m);
		int i;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a[i].t,&a[i].x);
		}
		sort(a,a+m,cmp);

		double max=0;
		for(i=1;i<m;i++)
		{
			double temp=(a[i].x-a[i-1].x)*1.0/(a[i].t-a[i-1].t)*1.0;
			temp=f(temp);
			if(max<temp)
				max=temp;
		}
		printf("Case #%d: %.2f\n",t,max);
		t++;

	}
	return 0;
	
}
