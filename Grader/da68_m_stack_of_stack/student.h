#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <vector>

// can include other libs or write util funtion here

template <typename T>
void CP::stack<T>::push(const T& value) {
    //write your code here
    std::vector<T> s;
    if(mSize == 0){
        s.push_back(value);
        mData.push_back(s);
        mSize = 1;
        return ;
    }
    if(mData.back().size()+1 <= mSize){
        // still can add
        mData.back().push_back(value);
    }
    else{
        std::vector<T> v;
        v.push_back(value);
        mData.push_back(v);
        mSize++;
    }
}

template <typename T>
void CP::stack<T>::pop() {
    if (size() == 0) throw std::out_of_range("index of out range") ;
	//write your code here
    if(mData.back().size() == 1){
        mData.pop_back();
        mSize--;
    }
    else{
        mData.back().pop_back();
    }
}

template <typename T>
size_t CP::stack<T>::size() const {
    //write your code here
    size_t cnt = 0;
    if(mSize == 0) return 0;
    if(mSize == 1) return 1;
    return (mSize * (mSize - 1)) / 2 + mData.back().size();
}

template <typename T>
const T&  CP::stack<T>::top() const {
    //write your code here
    if (size() == 0) throw std::out_of_range("index of out range") ;
    return mData.back().back();
}

/*
Push and pop with steady hand,
or tears may fall from teacher’s stand.
*/

#endif