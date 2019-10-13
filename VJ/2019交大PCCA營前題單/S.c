#include<stdio.h>
#define oo 2147483648
#define max(a,b) ((a)>(b)) ? (a):(b)
int n,k,i,f,t,ans;

int main()
{
    scanf("%d%d",&n,&k);
    for(i=0,ans=-oo;i<n;i++)
    {
        scanf("%d%d",&f,&t);
        if(t>k)
            ans = max(ans,f-t+k);
        else
            ans = max(ans,f);
    }
    printf("%d\n",ans);
    return 0;
}