#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    ll n; cin>>n;
    ll cnt = 0;
    ll l = 1;
    for(int i=0;i<n;i++){
        ll opr,k; cin>>opr>>k;
        if(opr==0) cnt += k;
        else cnt -= k;
        while(l<cnt) l*=2;
    }
    cout<<l-cnt;
    return 0;
}