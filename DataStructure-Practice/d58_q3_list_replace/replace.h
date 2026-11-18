void replace(const T& x, list<T>& y) {
  //write your code here
  iterator it = begin();
  int cnt = 0;
  while(it!=end()){
    if(it.ptr->data == x){
      iterator tmp = y.begin();
      it = erase(it);

      while(tmp != y.end()){
        it = insert(it,tmp.ptr->data).ptr->next;
        tmp = tmp.ptr->next;
      }
      continue;
    }
    it = it.ptr->next;
  }
}
