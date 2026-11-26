#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000003;
const int N = 1e4+10;
int dp[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,k; cin>>n>>k;
    vector<int> vec(k);
    for(auto& x:vec) cin>>x;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(auto x:vec){
            if(i-x >= 0){
                dp[i] = (dp[i] + dp[i-x] % MOD) % MOD;
            }
        }
    }
    // for(int i=0;i<=n;i++) cout<<dp[i]<<' ';
    // cout<<'\n';
    cout<<dp[n];
    return 0;
}
