#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010;
int p[N];
int fp(int i){
    if(p[i]==i) return i;
    return p[i]=fp(p[i]);
}
struct A{
    ll u,v,w;
    bool operator < (const A&o) const {
        return w<o.w;
    }
};
vector<A> vec;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m,u,k; cin>>n>>m>>u>>k;
    ll cnt = 0;
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--){
        ll u,v,w; cin>>u>>v>>w;
        vec.push_back({u,v,w});
    }
    sort(vec.begin(),vec.end());

    ll rem = n-1 - max(k-1,0);
    ll count = 0;

    for(int i=0;i<vec.size() && count<rem;i++){
        auto item = vec[i];
        int ru = fp(item.u);
        int rv = fp(item.v);
        ll w = item.w;
        if(ru!=rv){
            // cout<<"connecting "<<item.u<<' '<<item.v<<' '<<item.w<<' '<<p[ru]<<' '<<p[rv]<<'\n';
            // cout<<item.u<<' '<<item.v<<' '<<item.w<<' '<<rem<<'\n';
            count++;
            cnt+=w;
            p[rv] = ru;
        }
    }
    cout<<cnt * u;
    return 0;
}