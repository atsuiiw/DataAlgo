#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<iostream>

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if(a-begin() > b-begin()) std::swap(a,b);
  if(a-begin() < 0 || b-begin() >= mSize) return false;
  if(m==0) return false;
  if(a-begin() + m > b-begin()) return false;
  if(b-begin() + m >= mSize) return false;

  for(int i=0;i<m;i++){
    std::swap(*a,*b);
    a++;
    b++;
  }

  return true;
}

#endif
