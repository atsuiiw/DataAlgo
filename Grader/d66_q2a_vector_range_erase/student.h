#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <unordered_map>
#include <algorithm>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  if(ranges.size() == 0) return ;

  std::vector<int> vec(mSize);
  for(auto x:ranges){
    vec[x.first-begin()]++;
    vec[x.second-begin()]--;
  }
  int w = 0;
  T* arr = new T[mSize];
  for(int i=0;i<mSize;i++){
    if(i>0) vec[i] += vec[i-1];
    if(vec[i]==0){
      arr[w++] = mData[i];
    }
  }

  delete [] mData;
  mData = arr;
  mSize = w;
  mCap = w;

}

#endif