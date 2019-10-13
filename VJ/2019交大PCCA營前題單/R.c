#include<stdio.h>
#include<ctype.h>
#include<string.h>

int count[26];
char s[1007];
int n,i,j,k,flag;

int main()
{
    while(~scanf("%d%s",&n,s))
    {
        memset(count,0,sizeof(count));
        for(i=0;isprint(s[i]);i++)
            count[s[i]-'a']++;
        flag = 1;
        for(i=0;i<26;i++)
        {
            if(count[i]%n)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<26;j++)
                {
                    for(k=0;k<count[j]/n;k++)
                        printf("%c",j+'a');
                }
            }
            puts("");
        }
        else
            puts("-1");
        
    }
    return 0;
}