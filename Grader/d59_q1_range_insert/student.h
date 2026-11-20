#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  
  iterator it = position;
  for(iterator i = first; i!=last; i++){
    it = insert(it,*i) + 1;
  }
}

#endif