#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 705;
int c[N][N];
int dis[N];
struct A{
    int u,w;
    bool operator < (const A&o) const {
        return w>o.w;
    }
};
vector<A> vec[N];

priority_queue<A> pq;

void run(){
    memset(dis,0x3f,sizeof(dis));
    pq.push({1,0});
    dis[1] = 0;
    while(!pq.empty()){
        A top = pq.top();
        pq.pop();
        int u = top.u;
        int w = top.w;
        if(u==2){
            break;
        }
        for(auto x:vec[u]){
            if(dis[x.u] > w + x.w){
                dis[x.u] = w + x.w;
                pq.push({x.u,w+x.w});
            }
        }
    }
    while(!pq.empty()) pq.pop();
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>c[1][2];
    c[2][1] = c[1][2];
    vec[1].push_back({2,c[1][2]});
    vec[2].push_back({1,c[1][2]});
    for(int i=3;i<=n;i++){
        int k; cin>>k;
        while(k--){
            int v,w; cin>>v>>w;
            vec[i].push_back({v,w});
            vec[v].push_back({i,w});
        }
        run();
        cout<<dis[2]<<' ';
        // for(int j=1;j<=i;j++) cout<<dis[j]<<' ';
        // cout<<'\n';
    }
    return 0;
}