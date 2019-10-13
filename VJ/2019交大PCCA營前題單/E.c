#include<stdio.h>
#include<ctype.h>
#include<string.h>
char arr[26];
char s[107];
int c,i;
int main()
{
    while(fgets(s,sizeof(s),stdin))
    {
        memset(arr,0,sizeof(arr));
        for(i=0;islower(s[i]);i++)
            arr[s[i]-'a'] = 1;
        for(i=0,c=0;i<26;i++)
            if(arr[i])
                c++;
        printf("%s\n",(c&1) ? "IGNORE HIM!" : "CHAT WITH HER!");
    }
    return 0;
}
