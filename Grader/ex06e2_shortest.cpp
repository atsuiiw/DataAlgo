#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
struct A{
    int u,v,w;
};
vector<A> vec;
int dis[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    memset(dis,0x3f,sizeof(dis));
    int n,m,st; cin>>n>>m>>st;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        vec.push_back({u,v,w});
    }
    dis[st] = 0;

    for(int i=0;i<n;i++){
        for(auto x:vec){
            int u = x.u;
            int v = x.v;
            int w = x.w;
            if(dis[v] > dis[u] + w){
                if(i==n-1){
                    cout<<-1;
                    return 0;
                }
                dis[v] = dis[u] + w;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<dis[i]<<' ';
    return 0;
}