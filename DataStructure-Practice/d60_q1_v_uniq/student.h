#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include<unordered_map>

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  std::unordered_map<T,bool> vis;
  size_t cnt = 0;
  T* arr = new T[mSize];
  for(size_t i=0;i<mSize;i++){
    if(!vis[mData[i]]){
      arr[cnt++] = mData[i];
      vis[mData[i]] = true;
    }
  }
  delete [] mData;
  mData = arr;
  mSize = cnt;
  mCap = cnt;
}

#endif
