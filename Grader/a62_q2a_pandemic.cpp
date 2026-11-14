#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 1010;
queue<pii> qu;
pii dij[] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m,k; cin>>n>>m>>k;
    int cnt = 0;
    vector<vector<int>> val(n,vector<int>(m,0)), dis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>val[i][j];
            if(val[i][j]==1) qu.push({i,j}), dis[i][j] = 1, cnt++;
        }
    }
    // cout<<cnt;
    while(!qu.empty()){
        pii u = qu.front();
        qu.pop();
        for(auto x:dij){
            int ii = u.first + x.first;
            int jj = u.second + x.second;
            if(ii<0 || jj<0 || ii>=n || jj>=m) continue;
            if(val[ii][jj]==2) continue;
            if(dis[ii][jj]) continue;
            dis[ii][jj] = dis[u.first][u.second] + 1;
            cnt++;
            if(dis[ii][jj] > k) continue;
            qu.push({ii,jj});
        }
    }
    cout<<cnt;

    return 0;
}