#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2010;
int ci[N], co[N], dis[N];
vector<int> vec[N];
queue<int> qu;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    memset(dis,0x3f,sizeof(dis));
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++) cin>>ci[i];
    for(int i=0;i<n;i++) cin>>co[i];
    while(m--){
        int u,v; cin>>u>>v;
        vec[u].push_back(v);
    }
    dis[0] = 0;
    qu.push(0);
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(auto x:vec[u]){
            if(dis[x] > dis[u] + ci[x] + co[u]){
                dis[x] = dis[u] + ci[x] + co[u];
                qu.push(x);
            }
        }
    }
    for(int i=0;i<n;i++) cout<<(dis[i]<1e9 ? dis[i] : -1)<<' ';
    return 0;
}