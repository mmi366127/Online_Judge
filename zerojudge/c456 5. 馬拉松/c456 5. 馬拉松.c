#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define oo 1048576
#define MAXN 5007
#define max(a,b) a>b ? a:b
#define min(a,b) a<b ? a:b
#define swap(a,b) {int tmp=a;a=b;b=tmp;}
typedef struct Node N;
struct Node
{
    int v;
    N *next;
};
typedef struct queue
{
    N *start,*end;
}Q;
typedef struct pair
{
    int x,y;
}P;
// disjoint_set
int s[MAXN];
int p[MAXN];
Q adj[MAXN];
int e[MAXN];
P   g[MAXN];
int n,m,i,idx,k,a,b,ans;
N *iter;

int read();
void init();
int pop(Q*);
int find(int);
void push(Q*,int);
int join(int,int);
void reset_queue(Q*);
void reset_disjoint_set();
int main()
{
    n = read(); m = read();
    init();
    for(i=0;i<m;i++)
    {
        a = read(); b = read();
        push(adj+a,b);
        push(adj+b,a);
        e[a]++; e[b]++;
    }
    Q q;
    reset_queue(&q);
    idx = ans = 0;
    int c = 1;
    for(;;)
    {
        for(i=1,k=oo;i<=n;i++)
            if(e[i]>0)
                k = min(k,e[i]);
        if(k>=oo)
            break;
        for(i=1;i<=n;i++)
        {
            if(e[i]==k)
            {
                push(&q,i);
                e[i] = -1;
            }
        }
        for(;q.start;)
        {
            a = pop(&q);
            g[idx].x = a;
            g[idx++].y = k;
            for(iter=adj[a].start;iter;iter=iter->next)
                if(e[iter->v]>0 && --e[iter->v]<=k)
                    push(&q,iter->v),e[iter->v] = -1;
        }
    }
    for(idx--;idx>=0;idx--)
    {
        a = g[idx].x;
        e[a] = 1;
        for(iter=adj[a].start;iter;iter=iter->next)
        {
            b = iter->v;
            if(e[b]>0)
                ans = max(ans,join(a,b)*g[idx].y);
        }
    }
    printf("%d\n",ans);
    return 0;
}

int pop(Q *q)
{
    if(!q->start)
        return -1;
    N *ptr = q->start;
    int tmp = q->start->v;
    q->start = q->start->next;
    free(ptr);
    return tmp;
}
void push(Q *q,int v)
{
    if(q->start==NULL)
    {
        q->start = malloc(sizeof(N));
        q->end = q->start;
    }
    else
    {
        q->end->next = malloc(sizeof(N));
        q->end = q->end->next;
    }
    q->end->v = v;
    q->end->next = NULL;
}
int join(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x==y)
        return s[x];
    if(s[x]<s[y])
        swap(x,y);
    p[y] = x;
    s[x] += s[y];
    return s[x];
}
void init()
{
    reset_disjoint_set();
    int i;
    for(i=0;i<=n;i++)
        reset_queue(adj+i);
    memset(e,0,sizeof(e));
    memset(g,0,sizeof(g));
}
int find(int x)
{
    return p[x]<0 ? x : find(p[x]);
}
void reset_disjoint_set()
{
    for(i=0;i<=n;i++)
        s[i] = 1, p[i] = -1;
}
void reset_queue(Q *q)
{
    q->start = NULL;
    q->end = NULL;
}
int read()
{
    int tmp;
    static char c,neg;
    while((c=getchar())<'-')
        if(c==EOF) return 0;
    neg = c=='-' ? -1 : 1;
    tmp = c=='-' ? 0 : c-48;
    while((c=getchar())>='0')
        tmp = (tmp<<1) + (tmp<<3) + c - 48;
    tmp*=neg;
    return tmp;
}
