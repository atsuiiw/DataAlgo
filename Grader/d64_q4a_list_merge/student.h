#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for(auto& x:ls){
    if(x.size()==0) continue;
    iterator h = x.mHeader;

    // Connect last node to the first node of x
    mHeader->prev->next = h.ptr->next;
    h.ptr->next->prev = mHeader->prev;

    // Connect last node of x to head
    mHeader->prev = h.ptr->prev;
    h.ptr->prev->next = mHeader;

    mSize += x.mSize;
    x.mHeader->next = x.mHeader;
    x.mHeader->prev = x.mHeader;
    x.mSize = 0;
  }
}

#endif
