#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,q,N;

bool check(vector<int> v, int k){
    if(k==1) return v[0]==0 && v[1]==1;    

    vector<int> L,R;
    for(int i=0;i<v.size()/2;i++) L.push_back(v[i]);
    for(int i=0;i<v.size()/2;i++) R.push_back(v[i + v.size()/2]);

    bool left = check(L,k-1);
    bool right = check(R,k-1);
    reverse(L.begin(),L.end());
    bool revLeft = check(L,k-1);

    if((left || revLeft) && right) return true;
    return false;
}

void sol(){
    vector<int> vec(N);
    for(auto& x:vec) cin>>x;
    
    if(check(vec,n)) cout<<"yes\n";
    else cout<<"no\n";
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>q>>n;
    N = 1<<n;

    while(q--) sol();
    
    return 0;
}