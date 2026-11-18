#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

#include<iostream>

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    a = mSize-1-a;
    b = mSize-1-b;
    size_t k = a-b+1;
    if(mSize + k > mCap) expand(mSize + k);

    for(int i=mSize-1+k;i>a+k;i--){
        mData[i] = mData[i-k];
    }

    size_t w = a+k;
    for(int i=a;i>=b;i--){
        mData[w] = mData[i];
        mData[w-1] = mData[i];
        w-=2;
    }

    mSize = mSize + k;
    mCap = mSize;
}

#endif