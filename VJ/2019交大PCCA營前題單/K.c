#include<stdio.h>
typedef long long int loli;
loli n,m,a;

loli f();
int main()
{
    while(~scanf("%lld%lld%lld",&n,&m,&a))
        printf("%lld\n",f());
    return 0;
}
loli f()
{
    if(m%a==0&&n%a==0)
        return (m*n)/(a*a);
    else if(n%a==0)
        return (n/a)*((m/a)+1);
    else if(m%a==0)
        return (m/a)*((n/a)+1);
    else
        return ((m/a)+1)*((n/a)+1);
}