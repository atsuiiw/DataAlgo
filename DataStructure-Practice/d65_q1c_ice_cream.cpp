#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+10;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    ll n,m,st; cin>>n>>m>>st;

    vector<pair<ll,ll>> qs;
    vector<ll> ans(N);

    qs.push_back({0,st});
    for(int i=0;i<n;i++){
        ll d,x; cin>>d>>x;
        qs.push_back({d,x});
    }
    qs.push_back({N-1,qs.back().second});
    sort(qs.begin(),qs.end());

    for(int i=1;i<qs.size();i++){
        for(int j=qs[i-1].first;j<qs[i].first;j++){
            ans[j] = (j-1>=0 ? ans[j-1] : 0) + qs[i-1].second;
        }
    }

    while(m--){
        ll P,x; cin>>P>>x;
        auto it = lower_bound(ans.begin(),ans.end(),P) - ans.begin();
        if(it <= x){
            cout<<it<<' ';
            continue;
        }
        auto idx = lower_bound(ans.begin(),ans.end(),P + ans[x]) - ans.begin();
        cout<<idx<<' ';
    }

    return 0;
}