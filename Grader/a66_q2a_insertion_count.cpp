#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+10;
unordered_map<int,int> mp;
int temp[N], arr[N];

void merge(int l,int r){
    if(l==r) return ;
    int mid = (l+r)/2;
    merge(l,mid);
    merge(mid+1,r);
    int i = l, j = mid+1;
    int k = l;
    while(i<=mid && j<=r){
        if(arr[i] < arr[j]){
            // mp[arr[i]] += mid-i+1;
            temp[k++] = arr[i++];
        }
        else{
            mp[arr[j]] += mid-i+1;
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];
    for(int idx = l;idx<=r;idx++){
        arr[idx] = temp[idx];
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    merge(0,n-1);
    for(int i=0;i<m;i++){
        int p; cin>>p;
        cout<<mp[p]<<'\n';
    }
    
    return 0;
}