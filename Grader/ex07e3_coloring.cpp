#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 53;
vector<int> vec[N];
int color[N];

void coloring(int u,int l){
    if(color[u]) return ;
    color[u] = l;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!color[i]) continue;
        coloring(i,1);
    }
    return 0;
}