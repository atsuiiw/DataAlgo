#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

unordered_map<int,vector<int>> mp;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int N,D,T,Z; cin>>N>>D>>T>>Z;
    for(int i=0;i<D;i++){
        int t,z; cin>>t>>z;
        mp[t].push_back(z);
    }
    for(int i=0;i<N;i++){
        int k; cin>>k;
        for(int j=0;j<k;j++){
            int p; cin>>p;
            
        }
    }
    return 0;
}
