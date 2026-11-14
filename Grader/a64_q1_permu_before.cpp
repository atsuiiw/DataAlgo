#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 25;
using pii = pair<int,int>;

int n,k;
int arr[25];
int before[25];
void permu(int state, int mask){
    // cout<<mask<<" - ";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<' ';
    // }
    // cout<<'\n';
    if(state == n){
        for(int i=0;i<n;i++) cout<<arr[i]<<' ';
        cout<<'\n';
        return ;
    }

    for(int i=0;i<n;i++){
        if((1<<i) & mask) continue;
        if(before[i]!=-1 && !(1<<before[i] & mask)) continue;
        arr[state] = i;
        permu(state+1, mask | (1<<i));
    }

}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;i++) before[i] = -1;
    for(int i=0;i<k;i++){
        int a,b; cin>>a>>b;
        before[b] = a;
    }

    // for(int i=0;i<n;i++) cout<<before[i]<<' ';
    // cout<<'\n';
    for(int i=0;i<n;i++){
        if(before[i] != -1) continue;
        arr[0] = i;
        permu(1,(1<<i));
    }
    return 0;
}