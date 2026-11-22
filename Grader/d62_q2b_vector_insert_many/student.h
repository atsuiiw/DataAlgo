#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<algorithm>


template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  std::sort(data.begin(),data.end());

  ensureCapacity(mSize + data.size());

  for(int i=data.size()-1;i>=0;i--){
    insert(begin() + data[i].first, data[i].second);
  }

}

#endif
