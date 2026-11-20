#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

struct A{
    int score,n;
};

map<string,A> student, result;

void sol(){
    string id,s; int score;
    cin>>id>>s>>score;
    
    student[id].n += 1;
    student[id].score += score;

    result[s].n += 1;
    result[s].score += score;

    
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int q; cin>>q;
    while(q--) sol();
    for(auto x:student){
        cout<<fixed<<setprecision(2)<<x.first<<' '<< (x.second.score * 1.0) / x.second.n <<'\n';
    }
    for(auto x:result){
        cout<<fixed<<setprecision(2)<<x.first<<' '<< (x.second.score * 1.0) / x.second.n <<'\n';
    }
    return 0;
}