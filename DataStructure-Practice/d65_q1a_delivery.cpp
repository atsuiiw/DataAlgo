#include<bits/stdc++.h>
using namespace std;
using ll = long long;

queue<int> qu[2];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    ll n,m; cin>>n>>m;
    vector<ll> q(m);
    vector<ll> ans;
    for(auto& x:q) cin>>x;

    for(int i=0;i<n;i++){
        ll opr; cin>>opr;
        if(opr==1){
            ll type,val; cin>>type>>val;
            qu[type-1].push(val);
        }
        else{
            if(qu[0].empty()){
                ans.push_back(qu[1].front());
                qu[1].pop();
            }
            else if(qu[1].empty()){
                ans.push_back(qu[0].front());
                qu[0].pop();
            }
            else{
                ans.push_back(min(qu[0].front(),qu[1].front()));
                qu[0].front() <= qu[1].front() ? qu[0].pop() : qu[1].pop();
            }
        }
    }
    for(int i=1;i<ans.size();i++) ans[i] += ans[i-1];
    for(auto x:q){
        if(ans.empty()){
            cout<<"-1\n";
            continue;
        }
        int it = lower_bound(ans.begin(),ans.end(),x) - ans.begin();
        if(x > ans.back()) cout<<"-1 ";
        else cout<<it+1<<' ';
    }

    return 0;
}