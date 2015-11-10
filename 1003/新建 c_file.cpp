#include <stdio.h>
#include <string.h>

struct Mmax
{
	int mmax;
	int i,j;
}zuida;

int a[100005];

int main()
{
    int i,j,n,t;

	int tt=1;
    scanf("%d", &t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		zuida.mmax=a[0];
		zuida.i=1;
		zuida.j=1;

		int c = 0;
		int qi=0,mo=0;
		for(i=0; i<n; i++)
		{
			if(c >=0)
			{
				c = c+a[i];
				mo=i;
			}
			else 
			{
				c = a[i];
				qi=i;
				mo=i;
			}
			if(zuida.mmax < c)
			{
				zuida.mmax = c;
				zuida.i=qi+1;
				zuida.j=mo+1;
			}
		}
		if(tt!=1)
			printf("\n");
		printf("Case %d:\n",tt);
		tt++;
		printf("%d %d %d\n",zuida.mmax,zuida.i,zuida.j);
	}
  

    return 0;
}