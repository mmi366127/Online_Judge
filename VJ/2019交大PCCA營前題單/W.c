#include<stdio.h>
#define max(a,b) a>b ? a:b
int visited[2007];
int p[2007];
int n,i,ans;

int DFS(int x);
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",p+i);
    memset(visited,0,sizeof(visited));
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            ans = max(ans,DFS(i));
        }
    }
    printf("%d\n",ans);
    return 0;
}
int DFS(int x)
{
    visited[x] = 1;
    if(p[x]==-1)
        return 1;
    return DFS(p[x])+1;
}
