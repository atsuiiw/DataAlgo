#include <iostream>
#include <vector>
using namespace std;
void cross_2d(vector<vector<int>> &m ,int r1, int r2, int c1, int c2) {
    
    
    int R = m.size();
    int C = m[0].size();
    vector<vector<int>> vec(R-(r2-r1+1),vector<int>(C-(c2-c1+1),0));

    int r=0,c=0;
    for(int i=0;i<R;i++){
        if(i>=r1 && i<=r2) continue;
        c = 0;
        for(int j=0;j<C;j++){
            if(j>=c1 && j<=c2) continue;
            vec[r][c++] = m[i][j];
        }
        r++;
    }
    m = vec;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    vector<vector<int>> m;
    int r,c,r1,r2,c1,c2;
    cin>> r >> c;
    cin >> r1 >> r2 >> c1 >> c2;
    m.resize(r);
    for (int i =0;i < r;i++) {
        m[i].resize(c);
        for (int j = 0;j < c;j++) {
            cin >> m[i][j];
        }
    }
    cross_2d(m,r1,r2,c1,c2);
    for (int i =0;i < m.size();i++) {
        for (int j = 0;j < m[i].size();j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}