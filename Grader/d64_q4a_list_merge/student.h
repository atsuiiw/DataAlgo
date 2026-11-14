#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
#include<iostream>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here

  for(auto& x:ls){
    iterator it = x.mHeader;

    if(x.size() == 0) continue;
    
    mHeader->prev->next = it.ptr->next; // connect the end to start of new list
    it.ptr->next->prev = mHeader->prev; // connect at the end
    
    mHeader->prev = it.ptr->prev; // make it the last element by pointing mHeader->prev to it
    it.ptr->prev->next = mHeader; // make it->next the Header itself
    
    mSize+=x.mSize;
    
    x.mHeader->next = x.mHeader;
    x.mHeader->prev = x.mHeader;
    x.mSize = 0;
  }
  
}

#endif
