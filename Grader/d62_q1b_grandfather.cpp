#include<bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<ll,ll> p;

bool sol(){
    ll u,v; cin>>u>>v;
    
    // not in the family
    if(p.find(u) == p.end() || p.find(v) == p.end()) return false;
    
    // same person
    if(u==v) return false;

    // Is a child to the other
    if(p[u] == v || p[v] == u) return false;

    // Has no grandfather
    if(p[p[u]] == p[u] || p[p[v]] == p[v]) return false;
    
    // Has no father
    if(p[u]==u || p[v]==v) return false;

    // Is a grandfather to the other
    if(p[p[u]] == v || p[p[u]] == v) return false;

    if(p[p[u]] == p[p[v]] || p[u]==p[v]) return true;
    if(p[u]==p[v] && p[p[u]] != p[u]) return true;

    return false;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    ll n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        ll u,v; cin>>u>>v;
        p[v] = u;
        if(p.find(u) == p.end()) p[u] = u;
    }
    while(m--){
        cout<<(sol() ? "YES" : "NO")<<'\n';
    }
    return 0;
}