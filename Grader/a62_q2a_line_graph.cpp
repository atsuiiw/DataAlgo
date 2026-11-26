#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010;
vector<int> vec[N];
bitset<N> bs;

void run(int u,int p,bool& ch) {
    if(vec[u].size() > 2 || bs[u]) ch &= false;
    if(bs[u]) return ;
    bs[u] = true;
    for(auto x:vec[u]){
        if(x==p) continue;
        run(x,u,ch);
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        if(bs[i]==false){
            bool ch = true;
            run(i,i,ch);
            // cout<<i<<' '<<ch<<'\n';
            cnt += ch;
        }
    }
    cout<<cnt<<'\n';

    return 0;
}
