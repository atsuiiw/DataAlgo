#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
size_t CP::list<T>::fix_wrong() {

  iterator h = mHeader;
  size_t cnt = 0;
  while(h.ptr->next != mHeader){
    if(h.ptr->next == NULL || h.ptr->next->prev != h.ptr){
      cnt++;
      h.ptr->next->prev = h.ptr;
    }
    h = h.ptr->next;
  }
  
  return cnt;
}

#endif