#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010;
bitset<N> bs;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector<A> vec[N]; // node, weight
priority_queue<A> pq;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    vector<int> dis(N,1e9);
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x; cin>>x;
        bs[x] = true;
    }
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        if(bs[u] || bs[v]) continue;
        vec[u].push_back({v,w});
        vec[v].push_back({u,w});
    }
    pq.push({1,0});
    dis[1] = 0;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int u = top.v, w = top.w;
        for(auto x:vec[u]){
            if(dis[x.v] > w + x.w){
                dis[x.v] = w + x.w;
                pq.push({x.v,w + x.w});
            }
        }
    }
    cout<<dis[n];

    return 0;
}