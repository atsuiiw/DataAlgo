#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
const int INF = 0x3f3f3f3f;
int dis[N];
bool inq[N];
vector<pair<int,int>> adj[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m,k,V; cin>>n>>m>>k>>V;
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    for(int i=0;i<k;i++){
        int p; cin>>p;
        dis[p]=0;
        inq[p]=true;
        q.push(p);
    }
    for(int i=0;i<m;i++){
        int a,b,w; cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        inq[u]=false;
        for(auto [v,w]:adj[u]){
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                if(!inq[v]){ inq[v]=true; q.push(v); }
            }
        }
    }
    cout<<dis[V];
}