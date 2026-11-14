#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 22;

int a,b;
void permu(string s, int ones,int zeroes){
    if(s.size()==b){
        string ans = s;
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';
        return ;
    }
    if(ones) permu(s+"1",ones-1,zeroes);
    if(zeroes) permu(s+"0",ones,zeroes-1);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>a>>b;
    permu("",a,b-a);
    return 0;
}