#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

const int N = 1000010;
const int MOD = 1e9+7;
int dp[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4;i<=N-3;i+=2){
        dp[i] = (dp[i-2]*4 % MOD - dp[i-4] + MOD) % MOD;
    }
    cout<<dp[n] % MOD;
    return 0;
}
