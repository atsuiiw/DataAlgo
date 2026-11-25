#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3010;
int dp[N][N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    string s; cin>>s;
    s = " " + s;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s[i]==s[j]) dp[i][j] = dp[i][j-1] + 1;
            else dp[i][j] = dp[i][j-1];
        }
    }

    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            if(s[i]==s[j]) dp[i][j] = max({dp[i][j], dp[i+1][j-1] + 2});
            else dp[i][j] = max({dp[i][j],dp[i+1][j], dp[i][j-1], dp[i+1][j-1]});
        }
    }
    cout<<dp[1][n];
    return 0;
}