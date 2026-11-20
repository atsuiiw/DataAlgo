#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct A{
    int score;
    string s;
    bool operator < (const A&o) const{
        return score > o.score;
    }
};

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    
    unordered_map<string,int> mp;
    vector<int> vec;

    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        mp[s]++;
    }

    // for(auto x:mp){
    //     cout<<x.first<<' '<<x.second<<'\n';
    // }

    for(auto x:mp) vec.push_back(x.second);
    sort(vec.begin(),vec.end(),greater<int>());
    // vec.erase(unique(vec.begin(),vec.end()),vec.end());
    // for(auto x:vec) cout<<x<<' ';
    if(vec.size() < k) cout<<vec[vec.size()-1];
    else cout<<vec[k-1];
    return 0;
}