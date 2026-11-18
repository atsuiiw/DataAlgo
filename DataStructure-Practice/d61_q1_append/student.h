#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        if(s.size() == 0) return ;
        T* arr = new T[mSize + s.mSize];
        for(int i=0;i<s.mSize;i++){
            arr[i] = s.mData[i];
        }
        for(int i=0;i<mSize;i++){
            arr[i+s.mSize] = mData[i];
        }
        delete [] mData;
        mData = arr;
        mSize = mSize + s.size();
        mCap = mSize;
    }
    
    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        if(q.size() == 0) return ;
        T* arr = new T[mSize + q.mSize];
        for(int i=0;i<q.mSize;i++){
            arr[i] = q.mData[q.mSize-1 - i];
        }
        for(int i=0;i<mSize;i++){
            arr[i + q.mSize] = mData[i];
        }
        delete [] mData;
        mData = arr;
        mSize = mSize + q.mSize;
        mCap = mSize;
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        if(s.size() == 0) return ;
        T* arr = new T[mSize + s.mSize];
        for(int i=0;i<mSize;i++){
            arr[i] = mData[i];
        }
        for(int i=0;i<s.mSize;i++){
            arr[i+mSize] = s.mData[s.mSize-1 - i];
        }
        delete [] mData;
        mData = arr;
        mSize += s.mSize;
        mCap = mSize;
    }
    
    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        if(q.size() == 0) return ;
        T* arr = new T[mSize + q.mSize];
        for(int i=0;i<mSize;i++){
            arr[i] = mData[i];
        }
        for(int i=0;i<q.mSize;i++){
            arr[i+mSize] = q.mData[i];
        }
        delete [] mData;
        mData = arr;
        mSize += q.mSize;
        mCap = mSize;
    }
}
