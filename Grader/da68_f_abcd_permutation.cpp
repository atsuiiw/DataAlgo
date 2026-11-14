#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
vector<string> ans;
int n;

void run(int state,int a,int b,int c,int d,string acc){
    if(state==n){
        ans.push_back(acc);
        return ;
    }
    if(a>=1){
        run(state+1,a-1,b,c,d,acc+"A");
    }
    if(b>=1){
        run(state+1,a,b-1,c,d,acc+"B");
        
    }
    if(c>=1){
        run(state+1,a,b,c-1,d,acc+"C");
    }
    if(d>=1){
        run(state+1,a,b,c,d-1,acc+"D");
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    run(0,a,b,c,d,"");
    cout<<ans.size()<<'\n';
    for(auto x:ans) cout<<x<<'\n';
    return 0;
}