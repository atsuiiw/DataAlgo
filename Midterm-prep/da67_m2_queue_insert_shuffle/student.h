#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos)
{
	T* arr = new T[mSize + items.size()];

	if(items.size() == 0) return ;
	if(pos < 0 || pos > mSize) return ;

	int a=0,b=0,cur=0;
	for(int i=0;i<pos;i++){
		arr[cur++] = mData[(mFront + a++) % mCap];
	}
	for(int i=0; a<mSize && b<items.size();i++){
		if(i & 1)
			arr[cur++] = mData[(mFront + a++) % mCap];
		else
			arr[cur++] = items[b++];
	}
	
	while(a<mSize) arr[cur++] = mData[(mFront + a++) % mCap];
	while(b<items.size()) arr[cur++] = items[b++];

	delete [] mData;
	mData = arr;
	mFront = 0;
	mSize = mSize + items.size();
	mCap = mSize;
}

#endif
