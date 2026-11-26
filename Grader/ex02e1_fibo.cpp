#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50;
int dp[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    dp[1] = dp[2] = 1;
    for(int i=3;i<=N-1;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int q; cin>>q;
    cout<<dp[q];
    return 0;
}
