#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010;
int deg[N];
queue<int> qu;
vector<int> vec[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int u,v; cin>>u>>v;
        deg[u]++;
        deg[v]++;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(deg[i]==1) qu.push(i);
    }

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        deg[u] = 0;
        for(auto v:vec[u]){
            deg[v]--;
            if(deg[v]==1) qu.push(v);
        }
    }
    int mx = 0;
    for(int i=0;i<n;i++){
        if(deg[i]==2) mx++;
    }
    cout<<mx;
    return 0;
}