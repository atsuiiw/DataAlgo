#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
#include <queue>

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  if(k==0) return ;
  size_t w = 0;
  size_t rm = mSize % k;
  output.clear();
  for(size_t i=0;i<k;i++){
    std::queue<T> qu;
    for(size_t j=0;j<mSize/k + (i<rm) && w < mSize;j++) qu.push(mData[(mFront + w++) % mCap]);
    output.push_back(qu);
  }
}

#endif
