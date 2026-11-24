#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    vector<int> vec(n);
    for(auto& x:vec) cin>>x;
    while(m--){
        int k; cin>>k;
        int id = upper_bound(vec.begin(),vec.end(),k) - vec.begin() - 1;
        if(id == -1) cout<<"-1\n";
        else cout<<vec[id]<<'\n';
    }
    return 0;
}