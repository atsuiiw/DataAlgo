#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int N,D,T,Z;
    cin>>N>>D>>T>>Z;
    for(int i=0;i<D;i++){
        int w,item; cin>>w>>item;
        mp[item].push(w);
    }

    int ans = 0;
    bool ch = true;
    for(int i=0;i<N & ch;i++){
        int q; cin>>q;
        while(q--){
            int x; cin>>x;
            if(mp[x].empty() || mp[x].top() > T){
                ch = false;
                ans = i;
                break;
            }
            T -= mp[x].top();
            mp[x].pop();
        }
        if(!ch) break;
    }
    if(ch) cout<<N;
    else cout<<ans;

    return 0;
}