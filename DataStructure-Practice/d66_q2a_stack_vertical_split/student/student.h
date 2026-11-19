#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  int rm = mSize % k;
  int cur = mSize - 1;
  for(int i=0;i<k;i++){
    std::stack<T> st;

    for(int j=0;j<mSize/k + (rm>0);j++){
      st.push(mData[cur - mSize/k - (rm>0) + j + 1]);
    }
    cur -= mSize / k + (rm>0);
    rm--;

    output.push_back(st);
  }
}

#endif
