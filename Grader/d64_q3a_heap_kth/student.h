#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

#include<queue>


template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  // best-first walk over heap indices: the k-th item is reached after k-1 pops, no full copy
  auto cmp = [this](size_t a, size_t b) { return mLess(mData[a], mData[b]); };
  std::priority_queue<size_t, std::vector<size_t>, decltype(cmp)> cand(cmp);
  cand.push(0);
  for (size_t i = 1; i < k; i++) {
    size_t p = cand.top(); cand.pop();
    if (2 * p + 1 < mSize) cand.push(2 * p + 1);
    if (2 * p + 2 < mSize) cand.push(2 * p + 2);
  }
  for(int i=0;i<mSize;i++) std::cout<<mData[i]<<' ';
  std::cout<<'\n';
  return mData[cand.top()];
}

#endif