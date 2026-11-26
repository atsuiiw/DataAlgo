#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 1010;
bitset<N> vis[N];
int arr[N][N];

pair<pii,pii> dij[] = {
    {{},{}},
    {{0,-1},{0,1}},
    {{-1,0},{1,0}},
    {{-1,0},{0,1}},
    {{0,1},{1,0}},
    {{1,0},{0,-1}},
    {{0,-1},{-1,0}},
};
pii cal(pii a,pii b) {
    return {a.f-b.f,a.s-b.s};
}
bool canGo(pii u,pii v){
    if(arr[u.f][u.s] == 1){
        if(arr[v.f][v.s] == 1) return true;
        if(arr[v.f][v.s] == 1) return true;
    }
}
struct A{
    pii u;
    pii p;
};
queue<A> qu;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                int cnt = 1;
                vis[i][j] = true;
                while(!qu.empty()){
                    
                }
            }
        }
    }
    return 0;
}