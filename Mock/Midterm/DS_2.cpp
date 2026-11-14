#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

struct A{
    int room, guess;
    vector<pair<int,int>> vec; // room size, guess currently inhabitat

    void clear() {
        room = guess = 0;
        vec.clear();
    }
};

unordered_map<string,A> mp; // map group with A

void sol(){
    char op; cin>>op;
    if(op=='I'){
        int k,s; string g;
        cin>>k>>s>>g;
        mp[g].guess += k;
        mp[g].room += (k+s-1)/s;
    }
    else if(op=='O'){
        string g; cin>>g;
        mp[g].clear();
    }
    else if(op=='E'){
        int k,s; string g;
        cin>>k>>s>>g;
        mp[g].guess += k;
        
        // check how many guess can be fit at the last room
        
    }
    else if(op=='M'){
        string g; cin>>g;

    }
    else if(op=='S'){
        string g; cin>>g;

    }
    else{

    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int q; cin>>q;
    while(q--) sol();
    return 0;
}