#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10010;
vector<int> vec[N];
bitset<N> bs;
queue<int> qu;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(bs[i] == false){
            cnt++;
            qu.push(i);
            bs[i] = true;
            while(!qu.empty()){
                int u = qu.front();
                qu.pop();
                for(auto x:vec[u]){
                    if(bs[x]) continue;
                    bs[x] = true;
                    qu.push(x);
                }
            }
        }
    }
    cout<<cnt;

    return 0;
}