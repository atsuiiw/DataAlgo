#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5010;
int deg[N];
int cnt[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int p; cin>>p;
            if(p) deg[i]++, deg[j]++;
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++) cnt[deg[i]/2]++, mx=max(mx,deg[i]/2);
    for(int i=0;i<=mx;i++) cout<<cnt[i]<<' ';
    return 0;
}