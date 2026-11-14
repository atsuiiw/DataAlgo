
#include<iostream>

void replace(const T& x, list<T>& y) {
  //write your code here

  // run until find data = x
  iterator it = begin();
  while(it!=end()){
    // std::cout<<it.ptr->data<<' ';
    if(it.ptr->data == x){
      iterator tmp = y.begin();
      it = erase(it);
      while(tmp!=y.end()){
        it = insert(it,tmp.ptr->data).ptr->next;
        tmp = tmp.ptr->next;
      }
      continue;
    }
    it = it.ptr->next;
  }

  // node(data, pointer, pointer)
  // iterator it(begin());
  // iterator itY(y.begin());
  // for(size_t i=0;i<x-1;i++) it = it.ptr->next;
  // for(size_t i=0;i<y.size();i++){
  //   std::cout<<(it.ptr->data)<<' '<<(itY.ptr->data)<<'\n';
  //   it.ptr->data = itY.ptr->data;
  //   it = it.ptr->next;
  //   itY = itY.ptr->next;
  //   // *(begin()+x+i).ptr->data = *(y.begin() + i).ptr->data;
  // }
}
