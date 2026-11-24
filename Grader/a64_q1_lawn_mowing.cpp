#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500010;
int qs[N];



int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>qs[i];
    for(int i=1;i<n;i++) qs[i] += qs[i-1];

    while(m--){
        int a, b; cin>>a>>b;
        int l=a, r=n-1;
        int sub = (a>0 ? qs[a-1] : 0);
        while(l<r){
            int mid = (l+r+1)/2;
            int cal = (mid-a+1)*k + qs[mid] - sub;
            if(cal > b) r = mid-1;
            else l = mid;
        }
        if(l == a && qs[a] - sub + k > b) cout<<"0\n";
        else cout<<qs[l] - sub<<'\n';

    }
    return 0;
}