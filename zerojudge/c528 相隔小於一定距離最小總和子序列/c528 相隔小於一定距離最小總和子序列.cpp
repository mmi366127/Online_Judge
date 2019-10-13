#include<bits/stdc++.h>
#define maxn 1000007
using namespace std;

long long int dp[maxn];

int main(){
    int n,t,k,i;
    scanf("%d%d",&n,&k);
    deque<int> dq;
    dp[0] = 0;
    dq.push_back(0);
    for(i=1;i<=n;i++){
        scanf("%d",&t);
        while(!dq.empty() && dq.front() < i - k ) dq.pop_front();
        dp[i] = dp[dq.front()] + t;
        while(!dq.empty()&&dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    printf("%lld\n",dp[dq.front()]);
    return 0;
}
//dp[n] = min(dp[n-1]~dp[n-k]) + t;
