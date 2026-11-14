#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
queue<int> qu;
vector<pair<int,int>> vec[N];
vector<int> dis(N,1e9);
bitset<N> vis;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(i==j || x==-1) continue;
            vec[i].push_back({j,x});
        }
    }
    qu.push(1);
    dis[1] = 0;
    vis[1] = true;
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        vis[u] = true;
        for(auto x:vec[u]){
            if(vis[x.first]) continue;
            if(dis[u] + x.second < dis[x.first]){
                dis[x.first] = dis[u] + x.second;
                qu.push(x.first);
            }
        }
    }
    cout<<dis[n];

    return 0;
}