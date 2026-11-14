#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

vector<pair<int,int>> vec;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());
    // for(auto x:vec) cout<<x.first<<' '<<x.second<<'\n';
    while(m--){
        int a,b; cin>>a>>b;
        int l=0,r=n;
        while(l<r){
            int mid = (l+r)/2;
            if(vec[mid].first < a || (vec[mid].first==a && vec[mid].second <= b)) l = mid+1;
            else r = mid;
        }
        l = l-1;
        if(l < 0) cout<<"-1 -1 ";
        else if(vec[l].first==a && vec[l].second==b) cout<<"0 0 ";
        else cout<<vec[l].first<<' '<<vec[l].second<<' ';
    }
    return 0;
}