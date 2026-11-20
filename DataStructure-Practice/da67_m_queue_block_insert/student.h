#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	// 2 options, insert more front or insert more back
	size_t tail = mSize - p;

	ensureCapacity(mSize + m);

	// less elements on the back
	if(tail <= p){
		for(size_t i=mSize;i>p;i--){
			mData[(mFront + i-1 + m) % mCap] = mData[(mFront + i-1) % mCap];
		}
	}
	// less element on the front
	else {
		for(size_t i=0;i<p;i++){
			mData[(mFront - m + i + mCap) % mCap] = mData[(mFront + i) % mCap];
		}
		mFront = (mFront - m + mCap) % mCap;
	}

	for(size_t i=0;i<m;i++) mData[(mFront + p + i + mCap) % mCap] = element;
	mSize += m;
	// for(int i=0;i<mSize;i++){
	// 	std::cout<<mData[(mFront + i) % mCap]<<' ';
	// }
	// std::cout<<'\n';
}

#endif
