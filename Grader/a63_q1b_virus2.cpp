#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int q,n,N;
int check(vector<int> v,int k,bool& ch){
    if(k==1){
        return v[0] + v[1];
    }
    vector<int> L,R;
    for(int i=0;i<v.size()/2;i++) L.push_back(v[i]);
    for(int i=0;i<v.size()/2;i++) R.push_back(v[i+v.size()/2]);

    int a = check(L,k-1,ch);
    int b = check(R,k-1,ch);

    if(abs(a-b) > 1) ch = false;
    return a+b;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>q>>n;
    N = (1<<n);
    while(q--){
        vector<int> vec(N);
        for(auto& x:vec) cin>>x;
        bool ch = true;
        check(vec,n,ch);
        if(ch) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}