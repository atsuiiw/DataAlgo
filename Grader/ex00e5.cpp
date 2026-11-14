#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

vector<string> ans;
unordered_map<string,bool> mp;
int n,k;

void permu(int state,string s){ // state = how much 0 have we replaced with 1
    if(state==n-k) return ;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            string tmp = s;
            tmp[i] = '1';
            if(mp[tmp]) continue;
            mp[tmp] = true;
            ans.push_back(tmp);
            permu(state+1,tmp);
        }
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>k;

    string s(n,'0');
    for(int i=0;i<k;i++) s[s.size()-1-i] = '1';

    for(int i=0;i<n-k+1;i++){
        permu(0,s);
        ans.push_back(s);
        s = s.substr(1) + "0";
    }

    sort(ans.begin(),ans.end());
    // ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(auto x:ans) cout<<x<<'\n';

    return 0;
}