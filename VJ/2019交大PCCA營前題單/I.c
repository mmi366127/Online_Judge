#include<stdio.h>
typedef long long int loli;
loli n,i,tmp;
loli arr[100007];
loli dp[100007];
loli max(loli a,loli b){return a>b ? a:b;}
int main()
{
    scanf("%lld",&n);
    memset(arr,0,sizeof(arr));
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&tmp);
        arr[tmp]++;
    }
    dp[0] = 0;
    dp[1] = arr[1];
    for(i=2;i<=100000;i++)
    {
        dp[i] = max(arr[i]*i+dp[i-2],dp[i-1]);
    }
    printf("%lld\n",dp[100000]);
    return 0;
}
