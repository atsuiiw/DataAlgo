#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
int deg[N];
queue<int> qu;
vector<int> vec[N];

void sol(){
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        deg[u]++;
        deg[v]++;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i=0;i<n;i++) if(deg[i]==1) qu.push(i);

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        deg[u] = 0;
        for(auto x:vec[u]){
            if(deg[x]==0) continue;
            deg[x]--;
            if(deg[x] == 1){
                qu.push(x);
            }
        }
    }

    bool ch = false;
    for(int i=0;i<n;i++) if(deg[i] > 0){
        ch = true;
        break;
    }
    if(ch) cout<<"YES\n";
    else cout<<"NO\n";

    for(int i=0;i<n;i++) deg[i]=0, vec[i].clear();
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int q; cin>>q;
    while(q--) sol();
    return 0;
}