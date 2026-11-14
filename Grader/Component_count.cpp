#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10010;
vector<int> vec[N];
bool ch[N];
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
        if(!ch[i]){
            qu.push(i);
            ch[i] = true;
            while(!qu.empty()){
                auto u = qu.front(); qu.pop();
                for(auto v:vec[u]){
                    if(ch[v]) continue;
                    ch[v] = true;
                    qu.push(v);
                }
            }
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}