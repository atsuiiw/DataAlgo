#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<iostream>

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  //
  // std::cout<<k<<'\n';
  for(int i=0;i<k & i<mSize;i++){
    res.push_back(mData[(mFront + i) % mCap]);
  }
  // std::cout<<'\n';
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
}

#endif
