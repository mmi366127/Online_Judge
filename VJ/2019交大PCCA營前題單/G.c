#include<stdio.h>
#include<string.h>
char levels[101];
int n,t,i,flag;
int read();
int main()
{
    scanf("%d",&n);
    memset(levels,0,sizeof(levels));
    t = read();
    for(i=0;i<t;i++)
        levels[read()] = 1;
    t = read();
    for(i=0;i<t;i++)
        levels[read()] = 1;
    for(i=1,flag=1;i<=n;i++)
    {
        if(!levels[i])
        {
            flag = 0;
            break;
        }
    }
    puts((flag) ? "I become the guy.":"Oh, my keyboard!" );
    return 0;
}
int read()
{
    int tmp;
    static char c,neg;
    while((c=getchar())<'-')
        if(c==EOF) return 0;
    neg = (c=='-') ? -1 : 1;
    tmp = (c=='-') ? 0 : c-'0';
    while((c=getchar())>='0')
        tmp = (tmp<<1) + (tmp<<3) + c - '0';
    tmp*=neg;
    return tmp;
}
