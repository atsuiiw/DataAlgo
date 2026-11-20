#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
unordered_map<string,int> mp;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int q; cin>>q;
    while(q--){
        string s; cin>>s;
        mp[s]++;
    }
    vector<pair<string,int>> vec;
    for(auto x:mp){
        if(x.second <= 1) continue;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    for(auto x:vec){
        cout<<x.first<<' '<<x.second<<'\n';
    }
    return 0;
}