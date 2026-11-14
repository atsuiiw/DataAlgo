#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
vector<pair<int,int>> vec;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,s; cin>>n>>s;
    for(int i=1;i<=n;i++){
        int u,v; cin>>u>>v;
        vec.push_back({u,1});
        vec.push_back({v+1,-1});
    }
    
    sort(vec.begin(),vec.end());
    vector<int> num(vec.size()), qs(vec.size());

    for(int i=0;i<vec.size();i++) num[i] = vec[i].first;
    qs[0] = vec[0].second;
    for(int i=1;i<vec.size();i++){
        qs[i] = qs[i-1] + vec[i].second;
    }

    // for(auto x:num) cout<<x<<' ';
    // cout<<'\n';
    // for(auto x:qs) cout<<x<<' ';
    // cout<<'\n';

    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        auto itr = upper_bound(num.begin(),num.end(),x) - num.begin() - 1;
        // cout<<itr<<'\n';
        if(qs[itr] >= s) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}