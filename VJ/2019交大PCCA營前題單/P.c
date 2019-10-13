#include<stdio.h>
#include<ctype.h>

char s[107];
int i,flag;

int main()
{
    while(~scanf("%s",s))
    {
        flag = 0;
        for(i=1;isprint(s[i]);i++)
        {
            if(islower(s[i]))
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            puts(s);
        else
        {
            for(i=0;isprint(s[i]);i++)
            {
                if(islower(s[i]))
                    s[i] = toupper(s[i]);
                else
                    s[i] = tolower(s[i]);
            }
            puts(s);
        }
    }
    return 0;
}