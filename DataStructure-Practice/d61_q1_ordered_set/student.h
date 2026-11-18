#include <vector>
using namespace std;

#include<unordered_map>

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;

    v = A;
    std::unordered_map<T,bool> mp;
    for(auto x:A) mp[x] = true;
    for(auto x:B){
        if(mp.find(x) == mp.end()) v.push_back(x);
    }
    
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    
    std::unordered_map<T,bool> mp;
    for(auto x:B) mp[x] = true;
    for(auto x:A){
        if(mp.find(x) != mp.end()) v.push_back(x);
    }

    return v;
}
