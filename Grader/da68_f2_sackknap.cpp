#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10010;
int dp[N][N], value[N][N];
pair<int,int> val[N]; // w, p

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,w; cin>>n>>w;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>val[i].first>>val[i].second;
    }
    

    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j] = dp[i-1][j];
            if(j-val[i].first >= 0) dp[i][j] = min(dp[i][j],dp[i-1][j-val[i].first] + val[i].second);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++) cout<<(dp[i][j] >= 1e9 ? -1 : dp[i][j])<<' ';
        cout<<'\n';
    }
    return 0;
}