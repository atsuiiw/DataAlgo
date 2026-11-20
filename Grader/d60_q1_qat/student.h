#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  while(idx < 0) idx += mSize;
  return mData[(mFront + idx + mCap) % mCap];
}

#endif
