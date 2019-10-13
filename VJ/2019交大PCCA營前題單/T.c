#include<stdio.h>
#include<string.h>

char s[17];

int main()
{
    while(~scanf("%s",s))
        puts(solve(0,strlen(s)-1) ? "YES" : "NO" );
    return 0;
}
int solve(int a,int b)
{
    if(a>b || s[a]!='1')
        return 0;

    if(b==a && s[a]=='1')
        return 1;
    else if(b-a==1 && s[a]=='1' && s[b]=='4')
        return 1;
    else if(b-a==2 && s[a]=='1' && s[a+1]=='4' && s[b]=='4')
        return 1;

    int ret;
    if(s[a]=='1')
    {
        ret |= solve(a+1,b);
        if(s[a+1]=='4')
        {
            ret |= solve(a+2,b);
            if(s[a+2]=='4')
                ret |= solve(a+3,b);
        }
    }
    return ret;
}
