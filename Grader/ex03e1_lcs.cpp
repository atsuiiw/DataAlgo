#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 510;
int dp[N][N];
int path[N][N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    string a,b; cin>>a>>b;
    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                path[i][j] = 1;
            }
            else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                path[i][j] = 2;
            }
            else{
                dp[i][j] = dp[i][j-1];
                path[i][j] = 3;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<path[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    vector<char> vec;
    int i = n, j = m;
    while(i>0 && j>0){
        if(path[i][j] == 1){
            vec.push_back(a[i]);
            i--,j--;
        }
        else if(path[i][j] == 2){
            i--;
        }
        else j--;
    }

    cout<<vec.size();

    
    return 0;
}