#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3010;
int dp[N][N];
int st=1,mx=1;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; string s;
    cin>>n>>s;
    s = " "+s;
    for(int i=1;i<=n;i++) dp[i][i]=1;

    for(int i=1;i<n;i++) if(s[i]==s[i+1]) dp[i][i+1] = 1, mx=2;
    for(int size=3;size<=n;size++){
        for(int i=1;i<=n-size;i++){
            int j = i+size-1;
            if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j] = 1;
            if(dp[i][j]){
                mx = max(mx,j-i+1);
            }
        }
    }
    cout<<mx;
    return 0;
}