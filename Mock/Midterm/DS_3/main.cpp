#include "queue.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  CP::queue<int> A, B;
  int a, b, v;
  cin >> a >> b;
  for (int i = 0; i < a; i++) { cin >> v; A.push(v); }
  for (int i = 0; i < b; i++) { cin >> v; B.push(v); }

  string cmd, m, k;
  while (cin >> cmd && cmd != "q") {
    if (cmd == "s") {
      cin >> m;
      CP::queue<int> &t = (m == "A") ? A : B;
      cout << t.size() << " " << t.front() << " " << t.back() << "\n";
    } else if (cmd == "i") {
      cin >> m >> v;
      ((m == "A") ? A : B).push(v);
    } else if (cmd == "o") {
      cin >> m;
      ((m == "A") ? A : B).pop();
    } else if (cmd == "l") {
      cin >> m;
      CP::queue<int> t = (m == "A") ? A : B;
      bool first = true;
      while (!t.empty()) {
        if (!first) cout << " ";
        cout << t.front();
        t.pop();
        first = false;
      }
      cout << "\n";
    } else if (cmd == "f") {
      cin >> m >> k;
      ((m == "A") ? A : B).fusion((k == "A") ? A : B);
    }
  }
  return 0;
}
