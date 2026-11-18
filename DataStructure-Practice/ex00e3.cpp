#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+10;
bitset<N> bs;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    bool ch = true;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x <= 0 || bs[x] || x > n){
            ch = false;
            break;
        }
        bs[x] = true;
    }

    if(ch) cout<<"YES";
    else cout<<"NO";

    vector<int> v;
    vector<int>::iterator it = v.begin();
    v.push_back(1);
    std::cout<<it - v.begin();

    return 0;
}