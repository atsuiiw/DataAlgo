#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
int qs[N][N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,mx=-1000; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>qs[i][j];
            mx = max(mx,qs[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            qs[i][j] += qs[i-1][j-1];
            if(qs[i][j] >= 0) mx = max(mx,qs[i][j]);
            qs[i][j] = max(0,qs[i][j]);
        }
    }
    cout<<mx;
    return 0;
}