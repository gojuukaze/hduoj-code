#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define eps 1e-7
#define M 10001000
#define LL __int64
//#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535898
const int maxn = 1010;

using namespace std;

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int dp[maxn][30];
int sum[maxn];
int num[maxn];
int l[maxn];

int main()
{
    int n;
	int i,j,k;
    while(cin >>n)
    {
        if(!n)
            break;
        int m;
        cin >>m;
        for(i = 1; i <= m; i++)
            cin >>l[i];
        memset(dp, 0 , sizeof(dp));
        memset(sum, 0 , sizeof(sum));
        for(i = 1; i <= n; i++)
        {
            cin >>num[i];
            sum[i] = sum[i-1]+num[i];
        }
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                for(k = i-l[j]; k>= 0; k--)
				{
                    dp[i][j] = max(dp[i][j], dp[k][j-1]+sum[i]-sum[i-l[j]]);
					int aaaa=0;
				}
        int _max = 0;
        for(i = 1; i <= n; i++)
            _max = max(dp[i][m], _max);
        cout<<_max<<endl;
    }
    return 0;
}
