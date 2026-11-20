#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
int n,k;
unordered_map<string,bool> mp;
vector<string> ans;

void permu(string s,int state){
    if(state == n-k){
        return ;
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            string temp = s;
            temp[i] = '1';
            if(mp[temp]) continue;
            mp[temp] = 1;
            ans.push_back(temp);
            permu(temp,state+1);
        }
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>k;
    string s = "";
    for(int i=0;i<n-k;i++) s += "0";
    for(int i=0;i<k;i++) s += "1";

    for(int i=0;i<n-k+1;i++){
        ans.push_back(s);
        permu(s,0);
        s = s.substr(1) + "0";
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<'\n';
    return 0;
}