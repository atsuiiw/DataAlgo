#include<bits/stdc++.h>
using namespace std;

const int N = 1010;

int store[N][N];

void recur(int a,int b,int xi,int xj,int yi,int yj){
    if(a==0){
        // cout<<xi<<' '<<xj<<' '<<yi<<' '<<yj<<' '<<b<<'\n';
        store[xi][yi] = b;
        return ;
    }
    int midx = (xi+xj)/2;
    int midy = (yi+yj)/2;
    recur(a-1,b,xi,midx,yi,midy);
    recur(a-1,b-1,midx+1,xj,yi,midy);
    recur(a-1,b+1,xi,midx,midy+1,yj);
    recur(a-1,b,midx+1,xj,midy+1,yj);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int a,b; cin>>a>>b;
    recur(a,b,1,pow(2,a),1,pow(2,a));
    for(int i=1;i<=pow(2,a);i++){
        for(int j=1;j<=pow(2,a);j++){
            cout<<store[j][i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}