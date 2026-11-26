#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
double val[N];

struct A{
    int u,v;
    double w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector<A> vec;

int p[N];
int fp(int i){
    if(i==p[i]) return i;
    return p[i] = fp(p[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    for (int i = 0; i < n; i++) {
        cin>>val[i];
        p[i] = i;
    }
    for(int i=0;i<m;i++){
        int u,v;
        double w; cin>>u>>v>>w;
        w = sqrt(w*w + abs(val[u]-val[v])*abs(val[u]-val[v]));
        vec.push_back({u,v,w});
    }
    sort(vec.begin(),vec.end());
    double ans = 0;
    for(auto x:vec){
        int ru = fp(x.u);
        int rv = fp(x.v);
        double w = x.w;
        if(ru==rv) continue;
        ans += w;
        p[ru] = rv;
    }
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}
