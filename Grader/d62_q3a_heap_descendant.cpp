#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

int n,a;
vector<int> vec;
void recur(int u){
    vec.push_back(u);
    if(2*u + 1 <= n) recur(2*u+1);
    if(2*u + 2 <= n) recur(2*u+2);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>a;
    n--;
    recur(a);
    sort(vec.begin(),vec.end());
    cout<<vec.size()<<'\n';
    for(auto x:vec) cout<<x<<' ';
    return 0;
}