#include<bits/stdc++.h>

using namespace std;

map<int,unsigned int,greater<int> >DP;

int main()
{
    int i,j;
    int n,W;

    scanf("%d %d",&n,&W);
    DP[0]=0;
    for(i=0;i<n;i++)
    {
        int v,w;
        scanf("%d %d",&v,&w);
        for(auto it:DP)
        {
            if(it.first+w<=W && it.second+v>DP[it.first+w])
            {
                DP[it.first+w]=it.second+v;
            }
        }

        for(auto it=next(DP.begin());it!=DP.end();it++)
        {
            while(it!=DP.begin() && it->second>=prev(it)->second)
                DP.erase(prev(it));
        }
//        for(auto it:DP)
//            printf("(%d,%d)",it.first,it.second);
//        printf("\n");
    }
    unsigned int maxi=0;
    for(auto it:DP)
        maxi=max(maxi,it.second);
    printf("%u\n",maxi);

    return 0;
}
