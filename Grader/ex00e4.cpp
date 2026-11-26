#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 22;
int n,k;
int arr[N];

void permu(int state,int ones){

    if(state==n){
        if(ones != k) return ;
        for(int i=0;i<n;i++) cout<<arr[i];
        cout<<'\n';
        return ;
    }
    arr[state] = 1;
    permu(state+1,ones+1);
    arr[state] = 0;
    permu(state+1,ones);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>k>>n;
    permu(0,0);
    return 0;
}
