#include <iostream>
#include "map_bst.h"
#include "student.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    CP::map_bst<int, int> m;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m[x] = x;
    }

    const auto result = m.flatten();

    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << result[i];
    }

    cout << '\n';
    return 0;
}