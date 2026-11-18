#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  T* arr = new T[mSize+1];

  if(pos<0 || pos > mSize) return ;
  
  pos = mSize-pos;
  for(int i=mSize;i>pos;i--){
    arr[i] = mData[i-1];
  }
  for(int i=pos-1;i>=0;i--) arr[i] = mData[i];
  arr[pos] = value;

  delete [] mData;
  mData = arr; 
  mSize++;
  mCap=mSize;
}

#endif
