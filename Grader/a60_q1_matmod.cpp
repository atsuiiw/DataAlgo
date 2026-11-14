#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4;

struct MATRIX{
    int a[2][2];
    MATRIX () {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }
} arr[33];
int n,MOD;

MATRIX MUL(MATRIX A,MATRIX B){ // calculate A x B
    MATRIX res;
    int a = A.a[0][0];
    int b = A.a[0][1];
    int c = A.a[1][0];
    int d = A.a[1][1];
    int e = B.a[0][0];
    int f = B.a[0][1];
    int g = B.a[1][0];
    int h = B.a[1][1];

    res.a[0][0] = (a*e%MOD + b*g%MOD) % MOD;
    res.a[0][1] = (a*f%MOD + b*h%MOD) % MOD;
    res.a[1][0] = (c*e%MOD + d*g%MOD) % MOD;
    res.a[1][1] = (c*f%MOD + d*h%MOD) % MOD;

    return res;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>MOD;
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++) cin>>arr[0].a[i][j];
    }
    for(int i=1;i<=30;i++){ // store arr^(2^i)
        arr[i] = MUL(arr[i-1],arr[i-1]);
    }
    
    vector<bool> bin;
    int temp = n;
    while(temp){
        bin.push_back(temp%2);
        temp /= 2;
    }
    MATRIX res;
    res.a[0][0] = 1;
    res.a[1][1] = 1;
    for(int i=0;i<bin.size();i++){
        if(bin[i]) res = MUL(res,arr[i]);
    }
    cout<<res.a[0][0]<<' '<<res.a[0][1]<<' '<<res.a[1][0]<<' '<<res.a[1][1];

    return 0;
}