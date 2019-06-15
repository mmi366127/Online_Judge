#include<bits/stdc++.h>
typedef unsigned long long int loli;
using namespace std;

pair<string,string> seed[] = {{"a","b"},
                              {"aba","vac"},
                              {"aaaaiaaaaaaattczwaaxtabitc","aaaaqaaalaaattczlwaxtabaaa"},
                              {"kxaaeaaapraaaaraaaaakobaaa","kxaacalarazaaaraaaacvzzttv"},
                              {"aanaaeyaaaaaaaaamkaciykzza","eaaaiqidaaaaavaaveafjefqjk"},
                              {"aaapofeayahaaaaaaiapoedbru","aaafnasaytaaaaqaaaaeyobtaa"}};
loli hn[6] = {1,10007,1000000007,1000000000100011,3213213213213213,9007199254740992};
loli mod,s,num;
bool flag;
void dfs(int len,string &out,int sn){
    if(len == 0){
        cout<<out+seed[sn].first<<" "<<out+seed[sn].second<<'\n';
        num++;
        if(num == s){
            flag = false;
        }
        return;
    }
    for(char c='a';c<='z';c++){
        out[len] = c;
        dfs(len-1,out,sn);
        if(!flag)
            return;
    }
}
int main(){
    scanf("%llu%llu",&mod,&s);
    num = 0;
    int i;
    flag = true;
    for(i=0;i<6;i++)
        if(hn[i] == mod) break;
    string out;
    out.assign(4,'a');
    dfs(4,out,i);
    return 0;
}
