#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<algorithm>


template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  std::sort(data.begin(),data.end());
  T* arr = new T[mSize + data.size()];
  int shift = 0;
  
  for(int i=0;i<mSize;i++){
    if(data[shift].first == i){
      arr[i+shift] = data[shift].second;
      shift++;
    }
    arr[i+shift] = mData[i];
  }

  if(data[data.size()-1].first == mSize) arr[mSize+data.size()-1] = data[data.size()-1].second;

  delete [] mData;
  mData = arr;
  mSize = mSize + data.size();
  mCap = mSize;
}

#endif
