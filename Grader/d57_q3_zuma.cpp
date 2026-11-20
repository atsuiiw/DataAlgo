#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m,k; cin>>n>>m>>k;
    list<int> ls;
    for(int i=1;i<=n;i++){
        int p; cin>>p;
        ls.push_back(p);
    }

    auto it = ls.begin();
    it = next(it,m);
    ls.insert(it,k);
    it = next(it,-1);

    int cur = k;
    
    while(1){
        int L = 0, R = 0;
        while(*next(it,-L) == cur) L++;
        while(*next(it,R) == cur) R++;
        
        if(ls.empty() || R+L-1 < 3) break;

        it = next(it,-L+1);
        for(int i=0;i<R+L-1;i++){
            it = ls.erase(it);
        }

        if(ls.empty()) break;
        it = next(it,-1);
        cur = * it;
    }
    if(!ls.empty()) for(auto x:ls) cout<<x<<' ';

    return 0;
}