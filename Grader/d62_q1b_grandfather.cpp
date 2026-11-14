#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6+10;
int p[N];


int main(){
    cin.tie(nullptr)->sync_with_stdio(0);

    int n,m,cnt=0; cin>>n>>m;
    for(int i=0;i<n;i++) p[i] = i;
    unordered_map<string,int> mp;
    
    while(n--){
        string u,v; cin>>u>>v;
        if(mp.find(u) == mp.end()) mp[u] = cnt++;
        if(mp.find(v) == mp.end()) mp[v] = cnt++;
        p[mp[v]] = mp[u];
    }

    while(m--){
        string a,b; cin>>a>>b;

        bool ch = true;
        if(mp.find(a) == mp.end() || mp.find(b) == mp.end()){
            cout<<"NO\n";
            continue;
        }
        int u = mp[a];
        int v = mp[b];
        
        if(p[u] == u || p[v] == v) ch = false;
        if(v==u) ch = false;

        // check if they have grandparent
        if(p[p[u]] == p[u]) ch = false;
        if(p[p[v]] == p[v]) ch = false;

        // check if they share the same grandparent
        if(p[p[u]] != p[p[v]]) ch = false;

        if(ch) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}