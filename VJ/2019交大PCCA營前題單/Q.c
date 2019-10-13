#include<stdio.h>
#include<string.h>
char s1[1000],*p;
char s2[1000];
int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        p = strrev(s2);
        if(strcmp(s1,p)==0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
