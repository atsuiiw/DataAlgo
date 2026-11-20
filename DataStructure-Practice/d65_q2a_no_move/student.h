#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  //your code here
  auto it = std::lower_bound(aux.begin(),aux.end(),idx+1) - aux.begin();
  // debug();
  return mData[it][aux[it] - idx - 1];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  // update aux
  aux.resize(mData.size());
  for(int i=0;i<mData.size();i++){
    if(i==0) aux[i] = (mData[i].size());
    else aux[i] = (mData[i].size() + aux[i-1]);
  }
}

#endif
