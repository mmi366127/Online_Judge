#include<stdio.h>
typedef long long int loli;

loli n,k,i,c,all;

int main()
{
    scanf("%lld%lld",&n,&k);
    for(i=1,c=0;i*i<n;i++)
    {
        if(n%i==0)
            c++;
    }
    if(i*i==n)
        all = (c<<1)+1;
    else
        all = c<<1;
    if(k>all)
        puts("-1");
    else if(k==all)
        printf("%lld\n",n);
    else
    {
        if(k<=c)
        {
            for(i=1,c=0;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    c++;
                }
                if(c==k)
                {
                    printf("%lld\n",i);
                    return 0;
                }
            }
        }
        else
        {
            if(i*i==n)
            {
                k = all - k + 1;
            }
            else
            {
                k = all - k + 1;
            }
            for(i=1,c=0;i*i<=n;i++)
            {
                if(n%i==0)
                    c++;
                if(c==k)
                {
                    printf("%lld\n",n/i);
                    return 0;
                }
            }
        }
    }
    return 0;
}