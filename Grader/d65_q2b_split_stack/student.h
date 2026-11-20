#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  std::vector<std::vector<T>> vec;
  for(int i=0;i<k;i++){
    vec.push_back({});
    for(int j=mSize-1-i;j>=0;j-=k){
      vec.back().push_back(mData[j]);
    }
  std::reverse(vec.back().begin(),vec.back().end());
  }
  return vec;
}

#endif