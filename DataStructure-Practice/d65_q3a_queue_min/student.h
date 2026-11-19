#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here

  int w = 0;
  while(w < pos.size() && (pos[w] < 0 || pos[w] >= mSize)) w++;

  if(pos.size() == 0) return 0;
  T mn = mData[(mFront + pos[w]) % mCap];
  for(int i=w+1;i<pos.size();i++){
    if(pos[i] < 0 || pos[i] >= mSize) continue;
    if(comp(mData[(mFront + pos[i]) % mCap], mn)) mn = mData[(mFront + pos[i]) % mCap];
  }

  return mn;
}

#endif
