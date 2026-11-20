#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
#include<algorithm>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B
  if(pos.size() == 1 || pos.size() == 0) return ;
  if(mSize == 0) return ;
  std::sort(pos.begin(),pos.end());
  // for(auto x:pos) std::cout<<*x<<' ';
  // std::cout<<'\n';
  for(int i=pos.size()-2;i>=0;i--){
    size_t w = i+1;
    while(w<pos.size() && comp(*pos[w],*pos[w-1])){
      std::swap(*pos[w],*pos[w-1]);
      w++;
    }
  }
  // for(auto x:pos) std::cout<<*x<<' ';
  // std::cout<<'\n';
}

#endif
