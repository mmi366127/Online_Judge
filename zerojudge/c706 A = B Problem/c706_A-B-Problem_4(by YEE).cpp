#include<bits/stdc++.h>

#define ULLI unsigned long long int
using namespace std;

struct obj
{
    int idx;
    ULLI key;
    string str;
};

bool operator<(obj a,obj b)
{
    return a.key<b.key;
}

map<ULLI,bool>mp;
map<ULLI,string>mp2;
priority_queue<obj>pq;
ULLI chart[107];
vector<pair<ULLI,int> >lookup;
int len;
bool flag;
ULLI mod;
double gate;

void func()
{
    obj x=pq.top();
    pq.pop();
    cout<<x.str<<"   "<<x.key<<"\n";
    gate=(gate+x.key)/2;

    int i,j;
    bool check=0;
    for(i=x.idx;i<len;i++)
    {
        int now=lookup[i].second;
//            printf("now=%d, %llu\n",now,chart[now]);
        for(j=1;j<26;j++)
        {
            if(flag)
                return;

            ULLI next_key=(x.key+(chart[now]*j)%mod)%mod;
            string next_str=x.str;
            next_str[now]='a'+j;
            if(mp[next_key])
            {
                printf("bump. hash=%llu\n",next_key);
                cout<<mp2[next_key]<<" and "<<next_str<<"\n";
                flag=1;
                return;
            }
            else
            {
                mp[next_key]=1;
                mp2[next_key]=next_str;
                if(next_key>gate-100007)
                {
    //                cout<<next_str<<"   "<<next_key<<"\n";
                    if(i+1<len)
                    {
                        check=1;
                        pq.push({i+1,next_key,next_str});
                    }
                }
            }
        }
        if(check)
            break;
//        printf("retry...\n");
//        system("PAUSE");
    }
    return;
}

int main()
{
    int i;
    int S;

    scanf("%llu %d",&mod,&S);

    chart[25]=1;
    len=26;
    for(i=24;i>=0;i--)
    {
        chart[i]=(chart[i+1]*131)%mod;
    }
    for(i=0;i<=25;i++)
    {
        lookup.push_back({chart[i],i});
    }
    sort(lookup.begin(),lookup.end(),greater<pair<ULLI,int> >() );
//    for(i=0;i<=25;i++)
//    {
//        printf("%d %d\n",i,keep[i]);
//    }
    printf("len=%d\n",len);
    ULLI base_key=0;
    string base_str;
    for(i=0;i<len;i++)
    {
        base_key=(base_key*131+'a')%mod;
        base_str.push_back('a');
        printf("%llu %d\n",lookup[i].first,lookup[i].second);
    }
    cout<<base_str<<"\n";
    system("PAUSE");
    flag=0;
    pq.push({0,base_key,base_str});
    gate=0;
    while(!flag)
    {
        func();
//        system("PAUSE");
    }

    return 0;
}
