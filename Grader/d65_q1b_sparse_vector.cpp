#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int,int> &v, int pos, int value) {
    
    if(v.empty()){
        v.insert({pos,value});
        return ;
    }
    auto it = v.end();
    --it;
    while(it!=v.begin()){
        if((*it).first < pos) break;
        map<int,int>::iterator cur = it--;
        v.insert({(*cur).first+1,(*cur).second});
        v.erase(cur);
    }
    if(pos <= (*v.begin()).first){
        v.insert({(*v.begin()).first + 1, (*v.begin()).second});
        v.erase(v.begin());
    }
    v.insert({pos,value});
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    map<int,int> v;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        insert_into_sv(v,a,b);
    }
    cout << v.size() << "\n";
    for (auto &x : v) {
        cout << x.first << ": " << x.second << "\n";
    }
}