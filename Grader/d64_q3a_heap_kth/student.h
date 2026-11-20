#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"
#include<iostream>
#include<queue>

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here

  if(k==1) return mData[0];
  if(k==2) return (mLess(mData[1],mData[2]) ? mData[2] : mData[1]);
  if(k==3) return (mLess(mData[1],mData[2]) ? mData[1] : mData[2]);
}

#endif
