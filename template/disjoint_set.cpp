#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct DS {
    vector<int> p,s;
    int sz;
    DS(int _sz) : sz(_sz), p(_sz+1,-1), s(_sz+1,1) {}
    int find(int x){
        return (p[x]<0) ?  x : (p[x] = find(p[x]));
    }
    void join(int x,int y){
        x = find(x);
        y = find(y);
        if(x==y)
            return;
        if(s[x]<s[y])
            swap(x,y);
        p[y] = x;
        s[x] += s[y];
    }
    int size(int x){
        x = find(x);
        return s[x];
    }
};


int main(){
    DS  my_dis_joint_set(87);
    return 0;
}
