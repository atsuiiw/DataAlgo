#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
struct A{
    int p,r;
    bool operator < (const A&o) const{
        if(p!=o.p) return p<o.p;
        return r<o.r;
    }
};

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,q; cin>>n>>q;
    vector<A> vec(n);
    vector<ll> qs(n);
    for(int i=0;i<n;i++){
        int p,r; cin>>p>>r;
        vec[i] = {p,r};
    }
    sort(vec.begin(),vec.end());
    // for(auto x:vec) cout<<x.p<<' '<<x.r<<'\n';
    for(int i=0;i<n;i++){
        if(i==0) qs[i] = vec[i].r;
        else qs[i] = qs[i-1] + vec[i].r;
    }

    while(q--){
        int x; cin>>x;
        int index = lower_bound(qs.begin(),qs.end(),x) - qs.begin();
        index = max(index,0);
        cout<<vec[index].p<<'\n';
    }

    return 0;
}