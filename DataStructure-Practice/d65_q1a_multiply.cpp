#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void member_multiply(vector<int> &v,
vector<pair<vector<int>::iterator,int>> &multiply) {

    // auto cmp = [](const pair<vector<int>::iterator,int>& a, const pair<vector<int>::iterator,int>& b){
    //     return a.first > b.first;
    // };
    sort(multiply.begin(),multiply.end(),greater<>());

    vector<pair<int,int>> vec;
    for(auto x:multiply) vec.push_back({x.first - v.begin(),x.second});
    for(auto x:vec){
        int val = v[x.first];
        v.insert(v.begin() + x.first,x.second,val);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator,int>> multiply(m);
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        multiply[i].first = v.begin()+a;
        multiply[i].second = b;
    }
    member_multiply(v,multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}