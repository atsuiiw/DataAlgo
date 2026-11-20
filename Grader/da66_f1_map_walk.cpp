#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 12;
int n,m;
bool vec[N][N], vis[N][N];

const pii dij[] = {{0,1},{1,0},{-1,0}};

void run(pii u, string path){
    if(u.first == n-1 && u.second == m-1){
        cout<<path<<'\n';
        return ;
    }
    for(int k=0;k<3;k++){
        pii v = {u.first + dij[k].first, u.second + dij[k].second};
        if(v.first < 0 || v.second < 0 || v.first >= n || v.second >= m) continue;
        if(vis[v.first][v.second]) continue;
        if(vec[v.first][v.second]) continue;
        vis[v.first][v.second] = true;
        string temp = path;
        temp += ('A'+k);
        run(v,temp);
        vis[v.first][v.second] = false;
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>vec[i][j];
    vis[0][0] = true;
    run({0,0},"");
    cout<<"DONE";
    return 0;
}