#include<stdio.h>

long long int n,k;

int main()
{
    while(~scanf("%lld%lld",&n,&k))
    {
        if(n&1)
        {
            if(k<=(n>>1)+1)
            {
                printf("%lld\n",((k-1)<<1)+1);
            }
            else
            {
                k -= (n>>1)+1;
                printf("%lld\n",((k)<<1));
            }
        }
        else
        {
            if(k<=(n>>1))
            {
                printf("%lld\n",((k-1)<<1)+1);
            }
            else
            {
                k -= (n>>1);
                printf("%lld\n",((k)<<1));
            }
        }
    }
    return 0;
}
