#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 40010;
struct A{
    ll a,s;
    bool operator < (const A&o) const{
        return a<o.a;
    }
};
vector<A> vec;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    ll n,m,st; cin>>n>>m>>st;
    vec.push_back({0,st});
    for(int i=1;i<=n;i++){
        ll a,s; cin>>a>>s;
        vec.push_back({a,s});
    }
    
    sort(vec.begin(),vec.end());
    
    vector<ll> qs(n+1), event(n+1); // qs for amount and event for event points
    qs[0] = st;
    event[0] = vec[0].a;
    for(int i=1;i<=n;i++){
        qs[i] = qs[i-1] + (vec[i].a - vec[i-1].a - 1) * vec[i-1].s + vec[i].s;
        event[i] = vec[i].a;
    }

    while(m--){
        ll p,x; cin>>p>>x; // p = price, x = day
        ll index = upper_bound(qs.begin(),qs.end(),p) - qs.begin() - 1;
        if(index<0){
            cout<<0<<' ';
            continue;
        }
        ll day = event[index] + (p-qs[index] + vec[index].s-1) / vec[index].s;
        if (index + 1 <= n) day = min(day, event[index+1]);
        if(day <= x){
            cout<<day<<' ';
            continue;
        }
        
        index = upper_bound(event.begin(),event.end(),x) - event.begin() - 1;
        ll val = qs[index] + (x-event[index]) * vec[index].s;
        index = upper_bound(qs.begin(),qs.end(),p+val) - qs.begin() - 1;
        ll ans = event[index]+(p+val-qs[index] + vec[index].s-1) / vec[index].s;
        if (index + 1 <= n) ans = min(ans, event[index+1]);
        cout<<ans<<' ';
    }
    return 0;
}