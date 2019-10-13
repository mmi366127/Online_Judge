#include<stdio.h>
#include<string.h>
#define maxn 10007
#define H 1000000009
typedef long long int loli;

char S[maxn], s[maxn];
loli _hash[maxn];
loli base[maxn];

inline void init(int n){
    _hash[0] = 0;
    for(int i=1;i<=n;i++){
        _hash[i] = (_hash[i-1]*26 + S[i])%H;
    }
}
inline loli Get_hash(int l,int r){
    loli tmp = _hash[r] - _hash[l-1]*base[r-l+1]%H;
    if(tmp < 0)
        tmp += H;
    return tmp;
}

int main(){
    int t,n,i,j,len,ans,slen;
    loli Hnum;
    scanf("%d",&t);
    base[0] = 1;
    for(i=1;i<maxn;i++)
        base[i] = base[i-1]*26%H;

    while(t--){
        scanf("%s",S+1);
        scanf("%d",&n);
        len = strlen(S+1);
        init(len);
        for(i=1;i<=n;i++){
            scanf("%s", s+1);
            Hnum = 0; slen = strlen(s+1);
            for(j=1;j<=slen;j++)
                Hnum = (Hnum*26+s[j])%H;
            ans = 0; //printf("%d\n",Hnum);
            for(j=1;j<=len-slen+1;j++){
                if(S[j] == s[1] && Get_hash(j,j+slen-1) == Hnum)
                    ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
