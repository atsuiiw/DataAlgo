#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<bits/stdc++.h>

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  if(mSize < k) k = mSize;
  for(int i=0;i<k;i++){
    res.push_back(mData[(mFront + i) % mCap]);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
  
  size_t n = 0;
  for(auto i=from;i!=to;i++) n++;
  
  mCap = (n>0) ? n : 1;
  mData = new T[mCap];

  size_t w = 0;
  for(auto i=from;i!=to;i++){
    mData[w++] = *i;
  }

  mFront = 0;
  mSize = n;
}

#endif
