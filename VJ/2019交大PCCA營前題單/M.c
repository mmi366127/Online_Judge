#include<stdio.h>
typedef long long int loli;
loli n;
loli f(loli);
int main()
{
    while(~scanf("%lld",&n))
        printf("%lld\n",f(n));
    return 0;
}
loli f(loli n)
{
    if(n&1)
        return (n>>1)-n;
    else
        return n>>1;
}
