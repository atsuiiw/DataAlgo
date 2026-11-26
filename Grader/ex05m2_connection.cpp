#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
vector<int> vec[N];

int dis[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m,k; cin>>n>>m>>k;
    while(m--){
        int u,v; cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    int mx = 1;
    queue<int> qu;
    for(int i=0;i<n;i++){
        memset(dis,0,sizeof(dis));
        dis[i] = 0;
        qu.push(i);
        while(!qu.empty()){
            int u = qu.front();
            qu.pop();
            for(auto x:vec[u]){
                if(x==i) continue;
                if(dis[x] || x==i) continue;
                dis[x] = dis[u] + 1;
                qu.push(x);
            }
        }
        int cnt = 1;
        for(int j=0;j<n;j++) if(dis[j] <= k && dis[j]!=0 && i!=j) cnt++;
        // for(int j=0;j<n;j++) cout<<dis[j]<<' ';
        // cout<<'\n';
        // cout<<cnt<<'\n';
        mx = max(mx,cnt);
    }
    cout<<mx;
    return 0;
}
