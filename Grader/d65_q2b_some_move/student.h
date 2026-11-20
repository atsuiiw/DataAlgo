#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  if(value.empty()) return ;
  int it = std::lower_bound(aux.begin(),aux.end(), index+1) - aux.begin();
  if(it == aux.size()) it--;

  int st = index - (it > 0 ? aux[it - 1] : 0);
  mData[it].insert(mData[it].begin() + st, value.begin(), value.end());
  
  for(int i=it;i<mData.size();i++){
    aux[i] = (i>0 ? aux[i-1] : 0) + mData[i].size();
  }
  mSize += value.size();
}

#endif