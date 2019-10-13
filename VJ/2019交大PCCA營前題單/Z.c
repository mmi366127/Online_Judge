#include<stdio.h>
#include<math.h>
#define swap(a,b) {int loli=a;a=b;b=loli;}
int a,b;
int solve(int,int);
int main()
{
    while(~scanf("%d%d",&a,&b))
        printf("%d\n",solve(a,b));
    return 0;
}
int solve(int a,int b)
{
    if(a<b)
        swap(a,b);
    int k,t;
    k = a-b;
    t = k*(sqrt(5)+1)/2;
    return t==b ? 0 : 1;
}
