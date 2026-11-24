#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0)), dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    int mx = 0;
    for(int i=0;i<n;i++) mx = max(mx,dp[n-1][i]);
    cout<<mx;

    return 0;
}