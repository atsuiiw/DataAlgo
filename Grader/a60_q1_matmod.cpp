#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
int n,MOD;
int arr[2][2];

struct MATRIX{
    int a[2][2];

    MATRIX () {
        a[0][0] = 1;
        a[1][1] = 1;
        a[0][1] = 0;
        a[1][0] = 0;
    }
    
} m[35];

MATRIX mul(MATRIX a,MATRIX b) {
    MATRIX temp;
    int A = a.a[0][0];
    int B = a.a[0][1];
    int C = a.a[1][0];
    int D = a.a[1][1];

    int E = b.a[0][0];
    int F = b.a[0][1];
    int G = b.a[1][0];
    int H = b.a[1][1];

    temp.a[0][0] = (A*E % MOD + B*G % MOD) % MOD;
    temp.a[0][1] = (A*F % MOD + B*H % MOD) % MOD;
    temp.a[1][0] = (C*E % MOD + D*G % MOD) % MOD;
    temp.a[1][1] = (C*F % MOD + D*H % MOD) % MOD;
    return temp;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>MOD;
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            cin>>m[1].a[i][j];
            m[1].a[i][j] %= MOD;
        }
    }
    for(int i=2;(1<<(i-1))<=n;i++){
        m[i] = mul(m[i-1],m[i-1]);
    }

    vector<bool> vec;
    int temp = n;
    MATRIX res;

    while(temp){
        vec.push_back(temp & 1);
        temp /= 2;
    }
    cout<<'\n';
    for(int i=0;i<vec.size();i++){
        if(vec[i]) res = mul(res,m[i+1]);
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<res.a[i][j]<<' ';
        }
    }



    return 0;
}