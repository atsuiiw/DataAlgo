#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  if(last - first < 0) std::swap(first,last);
  size_t len = last - first;
  if(k==0 || len==0) return ;
  while(k<0) k += len;
  if(k % len == 0) return ;

  T* arr = new T[mSize + k];
  size_t f = first-begin();
  size_t l = last-begin();

  for(int i=0;i<f;i++) arr[i] = mData[i];
  for(int i=l;i<mSize;i++) arr[i] = mData[i];
  for(int i=0;i<k;i++){
    arr[l-k+i] = mData[f+i];
  }
  for(int i=0;i<l-f-k;i++){
    arr[f+i] = mData[f+k+i];
  }
  delete [] mData;
  mData = arr;
}

#endif
