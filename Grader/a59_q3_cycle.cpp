#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010;
vector<int> vec[N];
int dis[N],mx=0;

void dfs(int u,int p){
    for(auto v:vec[u]){
        if(v==p) continue;
        if(dis[v] > 0){
            // cout<<u<<' '<<dis[u]<<' '<<v<<' '<<dis[v]<<'\n';
            mx = max(mx,abs(dis[v]-dis[u])+1);
            return ;
        }
        dis[v] = dis[u]+1;
        dfs(v,u);
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int u,v; cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dis[0]=1;
    dfs(0,0);
    // for(int i=0;i<n;i++) cout<<dis[i]<<' ';
    cout<<mx;
    return 0;
}