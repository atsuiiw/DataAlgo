#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
list<int> ls;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,k,v; cin>>n>>k>>v;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        ls.push_back(x);
    }

    auto it = ls.begin();
    it = next(it,k);
    ls.insert(it,v);
    it = next(it,-1);

    int cur = v;
    while(1){
        int cntl=0,cntr=0;
        while(*next(it,-cntl) == cur) cntl++;
        while(*next(it,cntr) == cur) cntr++;
        
        // cout<<*it<<' '<<cur<<' '<<cntl<<' '<<cntr<<'\n';
        // if the length is less than 3 then no breaking should happen no more
        if(ls.empty() || cntr+cntl-1 < 3) break;
        auto tmp= next(it,-cntl+1);
        for(int i=0;i<cntl+cntr-1;i++){
            tmp = ls.erase(tmp);
        }
        if(ls.empty()) break;
        it = next(tmp,-1);
        cur = *it;
        // break;
    }

    if(!ls.empty()) for(auto x:ls) cout<<x<<' ';

    return 0;
}