#include<stdio.h>
int i,n,flag,a,b;
char s[100];
int color(int);
int main()
{
    scanf("%d",&n);
    for(i=0,flag=0;i<n;i++)
    {
        scanf("%s %d %d",s,&a,&b);
        if(color(a)==2&&b>a)
        {
            flag = 1;
            break;
        }
    }
    puts((flag) ? "YES":"NO");
    return 0;
}
int color(int n)
{
    if(n>=2400)
        return 2;
    else if(n>=2200)
        return 1;
    else
        return 0;
}
