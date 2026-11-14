#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {

  size_t newPos = mSize-pos;
  T *arr = new T[mSize+1]();
  for(size_t i = 0;i < newPos;i++){
    arr[i] = mData[i];
  }
  arr[newPos] = value;
  for (size_t i = newPos+1;i < mSize+1;i++) {
    arr[i] = mData[i-1];
  }
  delete [] mData;
  mData = arr;
  mCap = mSize+1;
  mSize = mSize+1;
}

#endif
