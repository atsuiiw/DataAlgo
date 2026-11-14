#include <iostream>
#include <vector>
#include <utility>
#include "segment_list.h"
#include "student.h"

using namespace std;
typedef CP::SegmentList<int> SL;

// prints what a cursor points at: its value and how many copies are left in its segment
// ("- 0" at end())
void printCursor(SL &L, SL::iterator it) {
  if (it.ptr == L.header()) cout << "- 0";
  else cout << it.ptr->val << " " << it.ptr->len - it.off;
}

// moves a cursor from element index `from` to element index `to`, one element at a time
void moveCursor(SL::iterator &it, long long from, long long to) {
  while (from < to) { ++it; from++; }
  while (from > to) { --it; from--; }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int K, Q;
  cin >> K >> Q;
  vector<pair<long long, int>> segs(K);
  for (auto &s : segs) cin >> s.first >> s.second;
  SL list(segs);
  SL::iterator A = list.begin(), B = list.begin();   // kept where rotate leaves them
  long long ia = 0, ib = 0;                          // element index of A and B
  while (Q--) {
    char c; cin >> c;
    if (c == 'q') break;
    if (c == 'r') {                                  // r a b k: rotate [a, b) right by k
      long long a, b, k; cin >> a >> b >> k;
      moveCursor(A, ia, a); moveCursor(B, ib, b); ia = a; ib = b;
      list.rotate(A, B, k);
      printCursor(list, A); cout << " "; printCursor(list, B);   // "<val at a> <run at a> <val at b> <run at b> <segments>"
      cout << " " << list.segments() << "\n";
    } else if (c == 'p') {                           // p s n: print n segments from segment s
      long long s, n; cin >> s >> n;
      cout << list.segments() << " " << list.size() << "\n";   // "<segments> <size>"
      SL::node *x = list.header()->next;
      for (long long i = 0; i < s; i++) x = x->next;
      for (; n > 0 && x != list.header(); n--, x = x->next) cout << x->len << " " << x->val << "\n";
    }
  }
}
