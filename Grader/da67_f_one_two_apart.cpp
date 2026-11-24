#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6+10;
const int MOD = 1e8+7;
pair<int,int> dp[N]; // sum, sub

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    dp[0] = {0,0};
    dp[1] = {3,1};
    dp[2] = {7,2};

    for(int i=3;i<=n;i++){
        int a = dp[i-1].first % MOD;
        int b = (dp[i-1].second*2 % MOD + dp[i-3].second) % MOD;
        dp[i] = {(a+(2*b%MOD)) % MOD,b % MOD};
    }
    cout<<dp[n].first;
    return 0;
}