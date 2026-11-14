#ifndef _CP_SEGMENT_LIST_INCLUDED_
#define _CP_SEGMENT_LIST_INCLUDED_

#include <vector>
#include <utility>

namespace CP {

template <typename T>
class SegmentList {
public:
  // one node = one segment: len copies of val
  class node {
  public:
    T val;
    long long len;
    node *prev, *next;
    node(const T &v, long long l, node *p, node *n) : val(v), len(l), prev(p), next(n) {}
  };

  class iterator {
  public:
    node *ptr;
    long long off;
    iterator(node *p = nullptr, long long o = 0) : ptr(p), off(o) {}
    T &operator*() { return ptr->val; }
    iterator &operator++() { // next element
      if (++off == ptr->len) { ptr = ptr->next; off = 0; }
      return *this;
    }
    iterator &operator--() { // previous element
      if (off == 0) { ptr = ptr->prev; off = ptr->len; }
      --off;
      return *this;
    }
    bool operator==(const iterator &o) const { return ptr == o.ptr && off == o.off; }
    bool operator!=(const iterator &o) const { return !(*this == o); }
  };

protected:
  node *mHeader;
  size_t mSegs;
  long long mSize;

public:
  // segs = list of (len, val); neighbouring values are different
  SegmentList(const std::vector<std::pair<long long, T>> &segs) : mSegs(0), mSize(0) {
    mHeader = new node(T(), 0, nullptr, nullptr);
    mHeader->prev = mHeader->next = mHeader;
    for (auto &s : segs) insert(end(), s.first, s.second);
  }

  ~SegmentList() {
    node *p = mHeader->next;
    while (p != mHeader) {
      node *q = p->next;
      delete p;
      p = q;
    }
    delete mHeader;
  }

  iterator begin() { return iterator(mHeader->next, 0); }
  iterator end() { return iterator(mHeader, 0); }
  size_t segments() const { return mSegs; }
  long long size() const { return mSize; }
  node *header() const { return mHeader; }

  iterator insert(iterator it, long long len, const T &v) {
    node *n = new node(v, len, it.ptr->prev, it.ptr);
    it.ptr->prev->next = n;
    it.ptr->prev = n;
    mSegs++;
    mSize += len;
    return iterator(n, 0);
  }

  iterator erase(iterator it) {
    node *n = it.ptr, *nx = n->next;
    n->prev->next = nx;
    nx->prev = n->prev;
    mSegs--;
    mSize -= n->len;
    delete n;
    return iterator(nx, 0);
  }

  void rotate(iterator &a, iterator &b, long long k);
};

}

#endif
