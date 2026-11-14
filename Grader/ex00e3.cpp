#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    set<int> s;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x<=0 || x>n) continue;
        s.insert(x);
    }
    if(s.size() < n ) cout<<"NO";
    else cout<<"YES";
    return 0;
}