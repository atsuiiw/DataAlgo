#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<queue>
#include<vector>

template <typename T>
void CP::vector<T>::aggregate(size_t l, size_t r){

    if(l > r) return;

    std::priority_queue<T> L;
    std::priority_queue<T,std::vector<T>,std::greater<T>> R;
    
    for(size_t i=l;i<=r;i++){
        L.push(mData[i]);

        // rebalance
        R.push(L.top());
        L.pop();

        // final balance
        while(L.size() < R.size()){
            L.push(R.top()); R.pop();
        }
    }
    
    T cur = L.top();
    T* arr = new T[mSize - (r-l)];
    arr[l] = cur;
    for(size_t i=0;i<l;i++) arr[i] = mData[i];
    size_t w = l+1;
    for(size_t i=r+1;i<mSize;i++) arr[w++] = mData[i];

    delete [] mData;
    mData = arr;
    mSize = mSize - (r-l);
    mCap = mSize;

    return;
}

#endif
