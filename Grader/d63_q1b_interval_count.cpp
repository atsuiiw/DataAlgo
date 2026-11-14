#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m,k; cin>>n>>m>>k;
    vector<int> vec(n);
    for(auto& x:vec) cin>>x;
    
    sort(vec.begin(),vec.end());

    while(m--){
        int p; cin>>p;
        int st = lower_bound(vec.begin(),vec.end(),p-k) - vec.begin() - 1;
        int en = upper_bound(vec.begin(),vec.end(),p+k) - vec.begin() - 1;
        cout<<en-st<<' ';
    }
    return 0;
}