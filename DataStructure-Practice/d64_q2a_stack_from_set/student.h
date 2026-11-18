#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  size_t w = 0, cur = 0;
  for(auto i=first;i!=last;i++) ++w;

  T* arr = new T[w];
  for(auto i=first;i!=last;i++) arr[w - 1 - cur++] = *i;
  mData = arr;
  mSize = w;
  mCap = mSize;
}

#endif
