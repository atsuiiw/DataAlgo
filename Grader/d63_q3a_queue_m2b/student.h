#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  if(pos >= mSize) return ;
  size_t idx = (mFront + pos) % mCap;
  T temp = mData[idx];
  // shifting all values from mFront+pos+1 to mFront+mSize-2
  for (size_t k=pos;k+1<mSize;k++) {
    size_t nxt = (idx + 1) % mCap;
    mData[idx] = mData[nxt];
    idx = nxt;
  }
  mData[(mFront+mSize-1)%mCap] = temp;

}

#endif
