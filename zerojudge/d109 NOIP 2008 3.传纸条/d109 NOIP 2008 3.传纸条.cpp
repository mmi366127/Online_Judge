#include<stdio.h>
#include<string.h>
#define maxn 60
#define maxm 8000
typedef struct Edge{
    int to, pre, w, flow;
}Edge;
Edge edge[maxm<<1];
int qu[maxm], dis[maxm], tag[maxn][maxn];
int start, end, tot;
int  head[maxm], pre[maxm], pe[maxm];
char inq[maxm];
void add(int u,int v,int w,int flow){
    edge[tot].to = v;
    edge[tot].flow = flow;
    edge[tot].w = w;
    edge[tot].pre = head[u];
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].flow = 0;
    edge[tot].w = -w;
    edge[tot].pre = head[v];
    head[v] = tot++;
}
int spfa(int s,int t){
    memset(inq,0,sizeof(inq));
    memset(pre,-1,sizeof(pre));
    memset(dis,-1,sizeof(dis));
    memset(pe,-1,sizeof(pe));
    start = 0; end = 0;
    qu[end++] = s; inq[s] = 1;
    dis[s] = 0;
    while(start != end){
        int x = qu[start++];
        if(start >= maxm )
            start %= maxm;
        inq[x] = 0;
        //printf("%d\n",x);
        for(int i=head[x];i!=-1;i = edge[i].pre){
            int y = edge[i].to;
            if(edge[i].flow > 0 && dis[y] < dis[x] + edge[i].w){
                //printf("ff%d\n",edge[i].flow);
                dis[y] = dis[x] + edge[i].w;
                pre[y] = x; pe[y] = i;
                if(!inq[y]){
                    qu[end++] = y;
                    if(end >= maxm)
                        end %= maxm;
                    inq[y] = 1;
                }
            }
        }
    }
    return dis[t] != -1;
}

int solve(int s,int t){
    int delta, ans = 0;
    while(spfa(s,t)){
        int p = t;
        delta = 1e9;
        ans += dis[t];
        while(pe[p]!=-1){
            //printf("edge : %d flow:%d\n",pe[p],edge[pe[p]].flow);
            if(delta > edge[pe[p]].flow)
                delta = edge[pe[p]].flow;
            p = pre[p];
        }
        //printf("flow%d\n",delta);
        p = t;
        while(p!=-1){
            edge[pe[p]].flow -= delta;
            edge[pe[p]^1].flow += delta;
            p = pre[p];
        }
    }
    return ans;
}



int main(){
    int n,m,i,j,c,f,t = 0;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&c);
            if((i==1&&j==1)||(i==n&&j==m)) f = 2;
            else f = 1;
            tag[i][j] = t;
            add(t*2,t*2+1,c,f);
            if(i>1){
                add(tag[i-1][j]*2+1,t*2,0,1);
            }
            if(j>1){
                add(tag[i][j-1]*2+1,t*2,0,1);
            }
            t++;
        }
    }
    printf("%d\n",solve(0,(tag[n][m]*2+1)));
    return 0;
}
