#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <vector>
#include <queue>

template <typename T, typename Comp>
std::vector<int> CP::priority_queue<T, Comp>::unordered_index() {
  std::vector<int> v;
  std::queue<int> qu;

  qu.push(0);
  while(!qu.empty()){
    size_t u = qu.front();
    qu.pop();
    if(2*u+1 >= mSize) continue; // leaf node
    if(2*u+2 >= mSize) continue; // only have left child
    if(mLess(mData[2*u+1],mData[2*u+2])){
      std::swap(mData[2*u+1],mData[2*u+2]);
      v.push_back(u);
    }
    qu.push(2*u+1);
    qu.push(2*u+2);
  }
  // for(int i=0;i<mSize;i++) std::cout<<mData[i]<<' ';
  // std::cout<<'\n';
  return v;
}

/*
 * It’s a "Priority Queue," or so we are told,
 * Where the "most important" is shiny and gold.
 * But don't be deceived by the order you see,
 * It’s sorted-ish chaos, if you're asking me.
 */

#endif
