#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7+2;
const int MOD = 1e8+7;
pair<int,int> dp[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);

    dp[1] = {3,1};

    for(int i=2;i<=N;i++){
        int a = ((dp[i-1].first % MOD) + 2*(dp[i-1].first%MOD - dp[i-1].second%MOD + MOD)) % MOD;
        int b = (dp[i-1].first%MOD - dp[i-1].second%MOD + MOD) % MOD;
        dp[i] = {a,b};
    }


    int q; cin>>q;
    cout<<dp[q].first;
    return 0;
}