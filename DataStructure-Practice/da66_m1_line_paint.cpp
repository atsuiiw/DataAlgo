#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 1010;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    vector<pii> vec(n);
    for(auto& x:vec){
        cin>>x.first>>x.second;
        x.second += 1;
    }
    sort(vec.begin(),vec.end(),[](const pii& a, const pii& b){
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    stack<pii> st;
    for(auto x:vec){
        if(st.empty()) st.push(x);
        else{
            int a = x.first;
            while(!st.empty() && x.first <= st.top().second){
                a = min(a,st.top().first);
                st.pop();
            }
            st.push({a,x.second});
        }
    }

    stack<pii> ans;
    while(!st.empty()){
        auto x = st.top();
        // cout<<x.first<<' '<<x.second-1<<'\n';
        ans.push(x);
        st.pop();
    }
    while(!ans.empty()){
        cout<<ans.top().first<<' '<<ans.top().second-1<<' ';
        ans.pop();
    }
    return 0;
}