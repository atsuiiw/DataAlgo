#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	if(mSize == 0) return ;
	if(last >= mSize) last = mSize - 1;
	if(first > last) return ;

	int l = mSize - 1 - last;
	int r = mSize - 1 - first;

	while(l<r){
		std::swap(mData[l],mData[r]);
		l++;
		r--;
	}
}

#endif
