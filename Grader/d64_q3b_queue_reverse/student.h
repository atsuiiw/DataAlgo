#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  if(a==b) return ;
  for(int i=a;i<=(a+b)/2;i++){
    std::swap(mData[(mFront+i) % mCap],mData[(mFront + b-(i-a) + mCap) % mCap]);
  }
}

#endif
