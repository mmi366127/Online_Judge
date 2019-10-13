#include<stdio.h>

int n,ans;

int main()
{
    while(~scanf("%d",&n))
    {
        ans = 0;
        while(n)
        {
            if(n&1)
                ans++;
            n>>=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
