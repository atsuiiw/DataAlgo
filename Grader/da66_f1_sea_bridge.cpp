#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 5010;
const pii dij[] = {{0,1},{0,-1},{1,0},{-1,0}};
int arr[N][N];
int dis[N][N];
queue<pii> qu;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                dis[i][j] = 1;
                qu.push({i,j});
            }
        }
    }

    int mn = n*m;

    while(!qu.empty()){
        pii u = qu.front();
        qu.pop();
        if(arr[u.first][u.second] == 2){
            mn = min(mn,dis[u.first][u.second]);
            continue;
        }
        for(int k=0;k<4;k++){
            pii v = {u.first + dij[k].first, u.second + dij[k].second};
            if(v.first < 1 || v.first > n || v.second < 1 || v.second > m) continue;
            if(dis[v.first][v.second]) continue;
            if(arr[v.first][v.second] == 3) continue;
            dis[v.first][v.second] = dis[u.first][u.second] + 1;
            qu.push(v);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<mn;
    return 0;
}