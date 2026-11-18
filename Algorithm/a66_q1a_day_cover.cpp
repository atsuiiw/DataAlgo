#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
int n,m,mn;
bool arr[N];
bitset<N> vec[25];

void permu(int state){
    if(state==m){
        int cnt = 0;
        bitset<N> temp;
        for(int i=0;i<m;i++){
            if(arr[i]){
                temp |= vec[i];
                cnt++;
            }
        }
        if(temp.count() == n){
            // for(int i=0;i<m;i++) cout<<arr[i]<<' ';
            // cout<<'\n';
            mn = min(mn,cnt);
        }
        return ;
    }
    arr[state] = false;
    permu(state+1);
    arr[state] = true;
    permu(state+1);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>m;
    mn = m;
    for(int i=0;i<m;i++){
        int k; cin>>k;
        for(int j=0;j<k;j++){
            int p; cin>>p;
            vec[i][p-1] = true;
        }
    }
    permu(0);
    cout<<mn;

    return 0;
}