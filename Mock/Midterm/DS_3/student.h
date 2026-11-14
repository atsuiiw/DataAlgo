#ifndef __STUDENT_H_
#define __STUDENT_H_

// You may include library here
#include "queue.h"
#include<bits/stdc++.h>

template <typename T>
void CP::queue<T>::fusion(CP::queue<T>& other) {
  bool self = (this == &other);
  // Work in the larger queue's buffer so only the overlapping tail is touched: O(min(n, m)).
  if (!self && mSize < other.mSize) {
    std::swap(mData, other.mData);
    std::swap(mCap, other.mCap);
    std::swap(mSize, other.mSize);
    std::swap(mFront, other.mFront);
  }
  size_t s = other.mSize;      // overlap length (queues aligned at the back)
  size_t start = mSize - s;    // first overlapping index in this
  size_t w = start;            // write index: dropping a zero shifts the rest left
  for (size_t i = start; i < mSize; i++) {
    T v = mData[(mFront + i) % mCap] + other.mData[(other.mFront + i - start) % other.mCap];
    if (v == 0) continue;      // erase summed item that became 0
    mData[(mFront + w++) % mCap] = v;
  }
  mSize = w;
  if (!self) other.mSize = 0, other.mFront = 0;
}

#endif
/*
4 6
1 2 3 4
5 0 6 -2 8 -9
l A
l B
f A B
l A
l B
q
*/