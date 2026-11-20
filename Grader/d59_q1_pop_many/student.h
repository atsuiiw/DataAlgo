#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  if(K >= mSize){
    mSize = 0;
  }
  else mSize-=K;
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  std::stack<T> st;
  for(int i=0;i<std::min(K,mSize);i++){
    // arr[len-1-i] = mData[mSize-1-i];
    st.push(mData[mSize-std::min(K,mSize) + i]);
  }

  multi_pop(K);
  return st;
}

#endif
