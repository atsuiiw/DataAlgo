#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 35;
int dp[N][N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);

    for(int i=0;i<=30;i++){
        dp[i][0] = dp[i][i] = 1;
        for(int j=1;j<i;j++) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
    }

    int n,r; cin>>n>>r;
    cout<<dp[n][r];
    return 0;
}