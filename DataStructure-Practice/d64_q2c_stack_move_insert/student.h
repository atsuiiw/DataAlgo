#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<iostream>

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  if(m==0) return ;
  if(s2.mSize < m) m=s2.mSize;
  if(k < 0 || k > mSize) return ;
  k = mSize - k;

  T* arr = new T[mSize + m];
  for(int i=0;i<k;i++) arr[i] = mData[i];

  int w = s2.mSize - m;
  for(int i=k;i<k+m;i++) arr[i] = s2.mData[w++];

  for(int i=k+m;i<mSize + m;i++){
    arr[i] = mData[i-m];
  }

  for(int i=0;i<m;i++) s2.pop();

  delete [] mData;
  mData = arr;
  mSize = mSize + m;
  mCap = mSize;
}
#endif
