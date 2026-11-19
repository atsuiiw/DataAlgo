#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)
  if(mSize == 0 && other.mSize > 0) return true;
  if(mSize > 0 && other.mSize == 0) return false;
  if(mData == other.mData) return false;

  size_t mnSize = std::min(mSize,other.mSize);

  for(int i=0;i<mnSize;i++){
    if(mData[i] > other.mData[i]) return false;
    if(mData[i] < other.mData[i]) return true;
  }
  if(mSize < other.mSize) return true;
  else return false;
}

#endif
