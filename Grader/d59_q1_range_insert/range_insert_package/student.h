#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  
  auto cur = first;
  while(cur!=last){
    position = insert(position,*cur) + 1;
    cur++;
  }
}

#endif
