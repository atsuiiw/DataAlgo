#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 510;
double R[N][N], dis[N];
vector<pair<int,double>> vec[N];

bool sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>R[i][j];
            vec[i].push_back({j,R[i][j]});
        }
    }
    queue<pair<int,int>> qu;
    for(int i=1;i<=n;i++){
        memset(dis,0x3f,sizeof(dis));
        dis[i] = 1;
        for(auto x:vec[i]) qu.push(x);
        while(!qu.empty()){
            auto u = qu.front();
            qu.pop();
        }
    }
    return false;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int q; cin>>q;
    while(q--)[
        if(sol()) cout<<"YES\n";
        else cout<<"NO\n";
    ]
    return 0;
}