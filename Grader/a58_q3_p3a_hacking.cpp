#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10010;

queue<int> qu;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m,k; cin>>n>>m>>k;
    vector<int> vec[n], dis(n,1e9), val(n), K(k);
    for(auto& x:K) cin>>x;
    for(auto& x:val) cin>>x;
    while(m--){
        int u,v; cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(auto x:K){
        qu.push(x);
        dis[x] = val[x];
    }

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(auto x:vec[u]){
            if(dis[x] > dis[u] + val[x]){
                dis[x] = dis[u] + val[x];
                qu.push(x);
            }
        }
    }

    int mx=0;
    for(auto x:dis) mx = max(mx,x);
    cout<<mx;

    return 0;
}