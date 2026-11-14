#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
unordered_map<string,int> mp;
vector<pair<int,string>> vec;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        mp[s]++;
    }
    for(auto x:mp){
        vec.push_back({-x.second,x.first});
    }
    sort(vec.begin(),vec.end());
    // for(auto x:vec) cout<<-x.first<<' '<<x.second<<'\n';
    cout<<-vec[min((int)vec.size()-1,m-1)].first;
    
    vector<int> temp = {1,2,3,4,5,6,7,8};
    
    return 0;
}