#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
struct A{
    int u,v,w;
    bool operator < (const A&o) const {
        return w<o.w;
    }
};
vector<A> mst;

int p[N];
int fp(int i){
    if(i==p[i]) return i;
    return p[i] = fp(p[i]);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0;i<n;i++) p[i] = i;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int w; cin>>w;
            mst.push_back({i,j,w});
        }
    }

    int cnt = 0;

    sort(mst.begin(),mst.end());
    for(auto x:mst){
        int ru = fp(x.u);
        int rv = fp(x.v);
        int w = x.w;
        if(ru == rv) continue;
        p[ru] = rv;
        cnt+=w;
    }
    cout<<cnt;
    return 0;
}