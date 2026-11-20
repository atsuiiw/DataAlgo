#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

vector<pii> vec;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        ll a,b; cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());
    
    int q; cin>>q;
    while(q--){
        ll a,b; cin>>a>>b;
        int l=0, r=k;
        while(l<r){
            int mid = (l+r)/2;
            // cout<<mid<<' '<<vec[mid].first<<' '<<vec[mid].second<<'\n';
            if(vec[mid].first < a || (vec[mid].first == a && vec[mid].second < b)) l = mid+1;
            else r = mid;
        }
        if(l==k) l = 0;
        ll cal = 0;
        if(make_pair(a,b) <= vec[l]){ // walk forward
            ll row = (abs(a-vec[l].first) - 1);
            if(row == -1) cal += vec[l].second - b;
            else cal += m-b + vec[l].second + row*m; // col
        }
        else{
            cal += (vec[l].first - 1) * m + vec[l].second;
            cal += (n-a) * m + m-b;
        }
        cout<<cal<<'\n';
    }
    return 0;
}