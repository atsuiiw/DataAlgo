#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10010;
const int MOD = 1e6+3;
int dp[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,k; cin>>n>>k;
    vector<int> vec(k);
    for(auto& x:vec){
        cin>>x;
        dp[x] = 1;
    }
    for(int i=1;i<=n;i++){
        for(auto x:vec){
            if(i-x < 0) continue;
            dp[i] += dp[i-x];
            dp[i]%=MOD;
        }
    }
    cout<<dp[n];
    return 0;
}