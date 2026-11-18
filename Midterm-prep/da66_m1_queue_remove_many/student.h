#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include<algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  if(mSize - pos.size() <= 0){
    mSize = 0;
    mFront = 0;
    mCap = mSize;
    return ;
  }

  std::sort(pos.begin(),pos.end());

  T* arr = new T[mSize - pos.size()];
  size_t w = 0, cur = 0, k = 0;

  while(w < mSize){
    if(k<pos.size() && pos[k] == w){
      k++;
      w++;
      continue;
    }
    arr[cur++] = mData[(mFront + w++) % mCap];
  }

  delete [] mData;
  mData = arr;
  mFront = 0;
  mSize = mSize - pos.size();
  mCap = mSize;
}

#endif
