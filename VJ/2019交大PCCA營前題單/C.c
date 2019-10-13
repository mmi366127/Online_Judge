#include<stdio.h>
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
        printf("%d\n",(n*m)>>1);
    return 0;
}