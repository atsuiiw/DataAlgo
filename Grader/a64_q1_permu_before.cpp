#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20+5;
int n,k;
int before[N], arr[N];

void permu(int state,int mask){
    if(state==n){
        for(int i=0;i<n;i++) cout<<arr[i]<<' ';
        cout<<'\n';
        return ;
    }
    for(int i=0;i<n;i++){
        if(mask & (1<<i)) continue;
        if(before[i] != -1 && !(mask & (1<<before[i]))) continue;
        arr[state] = i;
        permu(state+1,mask | (1<<i));
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);

    cin>>n>>k;
    for(int i=0;i<n;i++) before[i] = -1;
    for(int i=1;i<=k;i++){
        int a,b; cin>>a>>b;
        before[b] = a;
    }
    permu(0,0);
    return 0;
}