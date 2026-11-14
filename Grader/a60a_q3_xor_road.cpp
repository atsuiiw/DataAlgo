#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2010;


struct MST{
    int u,v;
    ll w;
    bool operator < (const MST&o) const{
        return w>o.w;
    }
};

vector<MST> vec;
vector<int> p(N);
int fp(int i){
    if(p[i]==i) return i;
    return p[i] = fp(p[i]);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;

    vector<ll> val(n);
    for(int i=0;i<n;i++) p[i] = i;
    
    for(auto& x:val) cin>>x;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll uw = val[i];
            ll vw = val[j];
            ll w = uw ^ vw;
            vec.push_back({i,j,w});
        }
    }
    sort(vec.begin(),vec.end());
    
    int cnt = 0;
    ll acc = 0;

    for(auto x:vec){
        if(cnt==n-1) break;
        int ru = fp(x.u);
        int rv = fp(x.v);
        ll w = x.w;
        if(ru!=rv){
            p[ru] = rv;
            cnt++;
            acc+=w;
        }
    }
    cout<<acc;

    return 0;
}