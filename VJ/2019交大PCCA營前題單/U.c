#include<stdio.h>
#define max(a,b) a>b ? a:b
int arr[1007];
int n,i,tmp,num,height;

int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        arr[tmp]++;
    }
    num = height = 0;
    for(i=1;i<1007;i++)
    {
        if(arr[i])
        {
            num++;
            height = max(height,arr[i]);
        }
    }
    printf("%d %d\n",height,num);
    return 0;
}