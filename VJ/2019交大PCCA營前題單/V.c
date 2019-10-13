#include<stdio.h>

int ans[107][107];
int n,i,j,num;

int main()
{
    scanf("%d",&n);
    num = 1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ans[j][i] = num++;
        }
        i++;
        for(j=n-1;j>=0;j--)
        {
            ans[j][i] = num++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    return 0;
}