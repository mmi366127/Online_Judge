#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b) ? a:b
char cake[17][17];
char s[17];
int n,m,ans,i,j,ns;

void DFS(int);
int eat(int,int);
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        fgets(s,sizeof(s),stdin);
        memset(cake,0,sizeof(cake));
        ns = 0;
        for(i=1;i<=n;i++)
        {
            fgets(s,sizeof(s),stdin);
            for(j=0;j<m;j++)
            {
                cake[j+1][i] = s[j]=='S' ? -128 : 1;
                if(s[j]=='.')
                    ns++;
            }
        }
        for(i=1;i<=m;i++)
            cake[i][0] = 1;
        for(i=1;i<=n;i++)
            cake[0][i] = 1;
        ans = 0;
        DFS(0);
        printf("%d\n",ans);
    }
    return 0;
}
void DFS(int num)
{
    if(ans>=ns)
        return;
    int i,t;
    ans = max(ans,num);
    for(i=1;i<=n;i++)
    {
        if( cake[0][i] && (t = eat(i,1)))
        {
            for(j=1;j<=m;j++)
                cake[j][i]--;
            cake[0][i] = 0;
            DFS(num+t);
        }
    }
    for(i=1;i<=m;i++)
    {
        if( cake[i][0] && (t = eat(i,2)))
        {
            for(j=1;j<=n;j++)
                cake[i][j]--;
            cake[i][0] = 0;
            DFS(num+t);
        }
    }
}
int eat(int num,int type)
{
    int i,count;
    if(type==1)
    {
        count = 0;
        for(i=1;i<=m;i++)
        {
            if(cake[i][num]==-128)
                return 0;
            else if(cake[i][num]>0)
                count++;
        }
        return count;
    }
    else
    {
        count = 0;
        for(i=1;i<=n;i++)
        {
            if(cake[num][i]==-128)
                return 0;
            else if(cake[num][i]>0)
                count++;
        }
        return count;
    }
}
