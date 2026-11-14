#include <vector>
#include<unordered_map>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_map<T,bool> mp;
    v = A;
    for(auto x:A) mp[x] = true;
    for(auto x:B){
        if(mp[x]==false) v.push_back(x);
    }
    
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_map<T,bool> mp;
    for(auto x:B) mp[x] = true;
    for(auto x:A){
        if(mp[x]) v.push_back(x);
    }
    return v;
}
