#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "compressed_vector.h"
#include <cstdlib>

template <typename T> void CP::CompressedVector<T>::expand(size_t capacity) {
  // write your code here
  size_t* arrL = new size_t[capacity]();
  T* arrV = new T[capacity]();
  for(int i=0;i<mSize;i++){
    arrL[i] = mDataL[i];
    arrV[i] = mDataV[i];
  }
  delete [] mDataL;
  delete [] mDataV;
  mDataL = arrL;
  mDataV = arrV;
  mCap = capacity;
}

template <typename T>
void CP::CompressedVector<T>::insert(int index, const T &element) {
  // write your code here
  
  if(mSize == 0){
    mSize = 1;
    if(mCap == 0) mCap = 1;
    mDataL[0] = 1;
    mDataV[0] = element;
    return ;
  }
  
  int cur = mDataL[0];
  size_t id = 0;
  while(id<mSize && cur <= index){
    cur += mDataL[++id];
  }

  if(id>0 && mDataV[id-1] == element){
    mDataL[id-1]++;
  }
  else if(id<mSize && mDataV[id] == element){
    mDataL[id]++;
  }
  else{
    size_t* arrL = new size_t[mSize + 1];
    T* arrV = new T[mSize + 1];
    for(size_t i=0;i<id;i++){
      arrL[i] = mDataL[i];
      arrV[i] = mDataV[i];
    }
    for(size_t i=id;i<mSize;i++){
      arrL[i+1] = mDataL[i];
      arrV[i+1] = mDataV[i];
    }

    arrL[id] = 1;
    arrV[id] = element;

    delete [] mDataV;
    delete [] mDataL;
    mDataV = arrV;
    mDataL = arrL;
    mSize++;
    ensureCapacity(mSize);
  }

  return ;
}

template <typename T> T &CP::CompressedVector<T>::operator[](int index) const {
  // write your code here

  int cur = mDataL[0];
  size_t i = 0;
  while(i<mSize && cur <= index){
    cur += mDataL[++i];
  }

  return mDataV[i];
}

#endif
