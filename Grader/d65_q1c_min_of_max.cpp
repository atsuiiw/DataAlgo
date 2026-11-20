#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

struct A{
    int val, type;
    bool operator < (const A&o) const {
        return val > o.val;
    }
};

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    vector<int> vec(n);
    for(auto& x:vec) cin>>x;

    unordered_map<int,int> mp; // map < team, power >
    priority_queue<A> pq;

    for(int i=0;i<m;i++) mp[i] = 1, pq.push({1,i});

    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x] = max(mp[x],vec[i]);

        pq.push({mp[x],x});
        while(!pq.empty() && pq.top().val != mp[pq.top().type]) pq.pop();

        cout<<pq.top().val<<' ';
    }

    return 0;
}