#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    size_t k = b - a + 1;
    size_t newSize = mSize + k;

    if (newSize > mCap)
        expand(std::max(newSize, mCap * 2));   // amortized, keeps old elements in place

    size_t r = mSize, w = newSize;
    for (int i = 0; i < a; i++) arr_move: mData[--w] = mData[--r];

    // middle k elements twice each
    for (size_t i = 0; i < k; i++) {
        T v = mData[--r];
        mData[--w] = v;
        mData[--w] = v;
    }

    mSize = newSize;
}

#endif