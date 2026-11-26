#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 510;
const int MOD = 1e8+7;
const pii dij[] = {{-1,1},{0,1},{1,1}};

int arr[N][N];
int dis[4][N][N];

struct A{
    pii u;
    int last;
};
queue<A> qu;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>arr[i][j];
    
    for(int i=1;i<=n;i++){
        if(arr[i][1]) continue;
        dis[0][i-1][2] = 1;
        dis[1][i][2] = 1;
        dis[2][i+1][2] = 1;
    }
    for(int j=2;j<m;j++){
        for(int i=1;i<=n;i++){
            if(arr[i][j]) continue;
            for(int k=0;k<3;k++){
                if(k!=0) dis[0][i-1][j+1] = (dis[0][i-1][j+1] + dis[k][i][j]) % MOD;
                if(k!=1) dis[1][i][j+1] = (dis[1][i][j+1] + dis[k][i][j]) % MOD;
                if(k!=2) dis[2][i+1][j+1] = (dis[2][i+1][j+1] + dis[k][i][j]) % MOD;
            }
        }
    }

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(arr[i][m]) continue;
        cnt = (cnt + dis[0][i][m] + dis[1][i][m] + dis[2][i][m]) % MOD;
    }
    cout<<cnt;


    return 0;
}