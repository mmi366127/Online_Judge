#include<stdio.h>
#include<ctype.h>
#include<string.h>
int letters[26];
char s[1987];
int i,tmp;
int main()
{
    while(~scanf("%s",s))
    {
        memset(letters,0,sizeof(letters));
        for(i=0;isprint(s[i]);i++)
        {
            letters[s[i]-'a']++;
        }
        for(i=0,tmp=0;i<26;i++)
            if(letters[i]&1)
                tmp++;
        puts( ( tmp==0 || tmp&1 ) ? "First" : "Second" );
    }
    return 0;
}
