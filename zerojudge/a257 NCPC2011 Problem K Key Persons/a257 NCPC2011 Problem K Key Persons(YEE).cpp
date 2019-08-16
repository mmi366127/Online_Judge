#include<bits/stdc++.h>
#define MAXI 30007
using namespace std;

vector<int>adj[MAXI];
vector<int>arr;
int v[MAXI];
int low[MAXI];
bool ap[MAXI];
int timer;

void DFS(int x,int p)
{
    v[x]=++timer;
    low[x]=timer;

    int child=0;
    for(auto y:adj[x])
    {
        if(y!=p)
        {
            if(v[y])
            {
                low[x]=min(low[x],v[y]);
            }
            else
            {
                child++;
                DFS(y,x);
                low[x]=min(low[x],low[y]);
                if(v[x]<=low[y] && x != p)
                    ap[x]=1;
            }
        }
    }
    if(x==p)
        ap[x]=(child>1);
}

int main()
{
    int i,j;
    int t;

    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(i=1;i<MAXI;i++)
        {
            adj[i].clear();
        }
        arr.clear();
        for(i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            arr.push_back(a);
        }
        for(i=0;i<arr.size();i++)
        {
            for(j=0;j<i;j++)
            {
                if(__gcd(arr[i],arr[j])>1)
                {
                    adj[arr[i]].push_back(arr[j]);
                    adj[arr[j]].push_back(arr[i]);
                }
            }
        }
        memset(v,0,sizeof(v));
        memset(low,0,sizeof(low));
        memset(ap,0,sizeof(ap));
        timer=0;
        for(auto it:arr)
        {
            if(!v[it])
                DFS(it,it);
        }

        int counti=0;
        for(auto it:arr)
        {
            if(ap[it])
                counti++;
        }
        printf("%d\n",counti);
    }

    return 0;
}

