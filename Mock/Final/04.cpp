#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+10;

struct A{
    ll u,w,k;
    bool operator < (const A&o) const{
        return w>o.w;
    };
};

vector<A> vec[N];
ll dis[23][N];
priority_queue<A> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dis,0x3f,sizeof(dis));
    ll n,m,k; cin>>n>>m>>k;
    while(m--){
        ll u,v,w; cin>>u>>v>>w;
        vec[u].push_back({v,w});
        vec[v].push_back({u,w});
    }

    pq.push({1,0,0});
    dis[0][1] = 0;
    while(!pq.empty()){
        A top = pq.top();
        pq.pop();
        ll u = top.u, w = top.w, K = top.k;
        if(u==n){
            cout<<w;
            return 0;
        }
        for(auto x:vec[u]){
            if(dis[K][x.u] > w+x.w){
                dis[K][x.u] = w+x.w;
                pq.push({x.u,w+x.w,K});
            }
            if(K+1<=k && dis[K+1][x.u] > w){
                dis[K+1][x.u] = w;
                pq.push({x.u,w,K+1});
            }
        }
    }
    return 0;
}
