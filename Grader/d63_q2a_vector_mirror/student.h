#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  if(mSize == 0) return ;
  T* arr = new T[mSize * 2];
  for(int i=0;i<mSize;i++){
    arr[i] = arr[mSize*2-1-i] = mData[i];
  }
  delete [] mData;
  mData = arr;
  mSize = mSize * 2;
  mCap = mSize;
}

#endif
