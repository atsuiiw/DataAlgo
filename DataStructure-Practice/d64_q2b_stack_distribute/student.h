#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  if(k<0) return {}; 
  int rm = mSize % k;
  std::vector<std::vector<T>> vec;
  for(int i=0;i<k;i++) vec.push_back({});
  int w = mSize-1;
  for(int i=0;i<k;i++){
    for(int j=0;j<mSize/k + (rm > 0);j++){
      if(w<0) break;
      vec[i].push_back(mData[w--]);
    }
    if(w<0) break;
    rm--;
  }
  return vec;
}
#endif
