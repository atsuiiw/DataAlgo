#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to) {
    // Write your code here
    if (mSize == 0 || from >= mSize || from > to) return;
    if(to>=mSize) to = mSize-1;
    size_t len = to-from+1;
    size_t trail = mSize - 1 - to;

    if(from < trail){
        for(int i=from-1;i>=0;i--){
            mData[(mFront + len + i) % mCap] = mData[(mFront + i) % mCap];
        }
        mFront = (mFront + len) % mCap;
    }
    else{
        for(int i=to+1;i<mSize;i++){
            mData[(mFront + i - len) % mCap] = mData[(mFront + i) % mCap];
        }
    }
    mSize -= len;

    return;
}
#endif