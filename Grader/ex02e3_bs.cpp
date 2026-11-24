#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,q; cin>>n>>q;
    vector<int> vec(n);
    for(auto& x:vec) cin>>x;
    while(q--){
        int k; cin>>k;
        int id = upper_bound(vec.begin(),vec.end(),k) - vec.begin() - 1;
        cout<<id<<'\n';
    }
    return 0;
}