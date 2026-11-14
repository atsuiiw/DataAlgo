#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;

vector<pair<int,int>> vec;
map<pair<int,int>,int> mp; // to map pair<int,int> u to index
int dis[N][N];

int cal(pair<int,int> u,pair<int,int> v){
    return abs(u.second - v.second) + abs((u.first + abs(u.second - v.second) - v.first));
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    memset(dis,sizeof(dis),0x3f);
    int n,q; cin>>n>>q;
    int index = 0;
    for(int i=0;i<n;i++){
        pair<int,int> u,v;
        cin>>u.first>>u.second>>v.first>>v.second;
        if(mp.find(u) == mp.end()) mp[u] = index++;
        if(mp.find(v) == mp.end()) mp[v] = index++;
        dis[mp[u]][mp[v]] = 1;
        dis[mp[v]][mp[u]] = 1;
    }
    for(auto x:mp) cout<<x.first.first<<' '<<x.first.second<<' '<<x.second<<'\n';
    for(int i=0;i<index;i++) dis[i][i] = 0;
    for(int i=0;i<index;i++){
        for(int j=0;j<index;j++){
            cout<<dis[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    while(q--){

    }
    return 0;
}