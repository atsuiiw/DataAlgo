#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,k; cin>>n>>k;
    queue<int> qu;
    qu.push(k);
    vector<int> vec;
    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        vec.push_back(u);
        if(u*2 + 1 < n) qu.push(u*2+1);
        if(u*2 + 2 < n) qu.push(u*2+2);
    }
    sort(vec.begin(),vec.end());
    cout<<vec.size()<<'\n';
    for(auto x:vec) cout<<x<<' ';
    return 0;
}