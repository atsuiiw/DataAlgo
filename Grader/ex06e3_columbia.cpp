#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 1010;
const pii dij[] = {{0,1},{0,-1},{1,0},{-1,0}};
int arr[N][N];
int dis[N][N];

struct A{
    pii u;
    int w;
    bool operator < (const A&o) const {
        return w>o.w;
    }
};
priority_queue<A> pq;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    memset(dis,0x3f,sizeof(dis));
    pq.push({{1,1},0});
    dis[1][1] = 0;
    while(!pq.empty()){
        pii u = pq.top().u;
        int w = pq.top().w;
        pq.pop();
        for(int k=0;k<4;k++){
            pii v = {u.first+dij[k].first, u.second+dij[k].second};
            if(v.first < 1 || v.first > n || v.second < 1 || v.second > m) continue;
            if(dis[v.first][v.second] > w + arr[v.first][v.second]){
                dis[v.first][v.second] = w + arr[v.first][v.second];
                pq.push({v,dis[v.first][v.second]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<dis[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}