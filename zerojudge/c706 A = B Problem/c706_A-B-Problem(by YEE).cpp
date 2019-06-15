#include<bits/stdc++.h>

#define ULLI unsigned long long int
using namespace std;
ULLI _[6] = {1,10007,1000000007,3213213213213213,9007199254740992,1000000000100011};

struct obj
{
    ULLI key;
    string str;
};
bool operator<(obj a,obj b)
{
    return a.key<b.key;
}

set<ULLI>st;
map<ULLI,string>mp2;
priority_queue<obj>pq;
bool flag;
ULLI mod;

void func()
{
    obj x=pq.top();
    pq.pop();
    //cout<<x.str<<"   "<<x.key<<"\n";

    char c;
    for(c='a';c<='z';c++)
    {
        if(flag)
            return;
        ULLI next_key=(x.key*131+c)%mod;
        string next_str=x.str+c;
        if(st.find(next_key) != st.end())
        {
            printf("bump.\n");
            cout<<mp2[next_key]<<" and "<<next_str<<"\n";
            flag=1;
            return;
        }
        else
        {
            if((x.key*131+c)%mod>x.key)
            {
//                cout<<next_str<<"   "<<next_key<<"\n";
                st.insert(next_key);
                mp2[next_key]=next_str;
                pq.push({next_key,next_str});
            }
        }
    }
}
void init(){
    st.clear();
    mp2.clear();
    while(!pq.empty())
        pq.pop();
    pq.push({0,""});
    flag = 0;
}
int main()
{/*
    scanf("%llu",&mod);
    flag=0;
    pq.push({0,""});*/
    /*string init, tmp;
    ULLI h = 0;
    while(1){
        tmp = pq.top().str;

        for(char c='a';c<='z';c++){
            pq.
        }
    }
    while(!pq.empty()){
        pq.pop();
    }
    pq.push({0,init});*/
    pq.push({449810631840396,"aaaaaaaa"});
    for(int i=3;i<=3;i++){
        init();
        while(!flag){
            mod = _[i];
            func();
        }
    }/*
    while(!flag)
    {
        func();
//        system("PAUSE");
    }*/
    while(1);
    return 0;
}
