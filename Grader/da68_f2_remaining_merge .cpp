#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200010;
int vec[N];
int sum = 0;

void merge(int l,int r){
    if(l>=r) return ;
    int mid = (l+r)/2;
    merge(l,mid);
    merge(mid+1,r);
    int i = l;
    int j = mid+1;
    int idx = l;
    int temp[N];
    while(i<=mid && j<=r){
        if(vec[i] <= vec[j]) temp[idx++] = vec[i++];
        else temp[idx++] = vec[j++];
    }
    while(i<=mid){
        temp[idx++] = vec[i++];
        sum++;
    }
    while(j<=r){
        temp[idx++] = vec[j++];
        sum++;
    }

    for(int i=l;i<=r;i++) vec[i] = temp[i];
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>vec[i];
    merge(1,n);
    cout<<sum;
    // for(int i=1;i<=n;i++) cout<<vec[i];
    return 0;
}