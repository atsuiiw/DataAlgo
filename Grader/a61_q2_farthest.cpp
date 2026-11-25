#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
struct A{
    int u,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector<A> vec[N];
priority_queue<A> pq;
int dis[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    memset(dis,0x3d,sizeof(dis));
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int p; cin>>p;
            if(i==j || p==-1) continue;
            vec[i].push_back({j,p});
        }
    }
    pq.push({1,0});
    dis[1] = 0;
    while(!pq.empty()){
        A top = pq.top();
        pq.pop();
        int u = top.u, w = top.w;
        for(auto x:vec[u]){
            if(dis[x.u] > w+x.w){
                dis[x.u] = w+x.w;
                pq.push({x.u,w+x.w});
            }
        }
    }
    int mx = 0;
    for(int i=2;i<=n;i++) mx = max(mx,dis[i]);
    cout<<mx;
    return 0;
}