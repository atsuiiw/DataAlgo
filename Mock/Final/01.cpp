#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 30;

int arr[N];
int n,m;
char ans[N];
vector<string> vec;
unordered_map<string,bool> mp;

void run(int state){
    if(state==n){
        string s = "";
        for(int i=0;i<n;i++) s += ans[i];
        reverse(s.begin(),s.end());
        if(!mp[s]){
            reverse(s.begin(),s.end());
            mp[s] = true;
            vec.push_back(s);
        }
        return ;
    }
    for(int i=0;i<m;i++){
        if(arr[i]==0) continue;
        arr[i]--;
        ans[state] = ('A'+i);
        run(state+1);
        arr[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for (int i = 0; i < m; i++) cin>>arr[i];
    run(0);
    cout<<vec.size()<<'\n';
    for(auto x:vec) cout<<x<<'\n';
    return 0;
}
