#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
vector<int> vec;
queue<int> qu;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    if(m==0){
        cout<<0;
        return 0;
    }
    qu.push(0);
    vec.push_back(0);
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        if(2*u+1 < n && 2*u+1 != m){
            vec.push_back(2*u+1);
            qu.push(2*u+1);
        }
        if(2*u+2 < n &&  2*u+2 != m){
            vec.push_back(2*u+2);
            qu.push(2*u+2);
        }
    }
    cout<<vec.size()<<'\n';
    for(auto x:vec) cout<<x<<' ';

    return 0;
}