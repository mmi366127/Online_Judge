#include<stdio.h>
#include<string.h>
char s[100007],*p;

int main()
{
    scanf("%s",s);
    if((p=strstr(s,"AB"))&&strstr(p+2,"BA")) puts("YES");
    else if((p=strstr(s,"BA"))&&strstr(p+2,"AB")) puts("YES");
    else puts("NO");
    return 0;
}
