#ifndef _STUDENT_H_
#define _STUDENT_H_

// you can also include anything else here
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>


std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  std::vector<size_t> r;
  //write your code here
  
  std::vector<int> vec;
  for(auto x:data) vec.push_back(x.second);
  std::sort(vec.begin(),vec.end());


  for(auto x:queries){
    auto L = std::lower_bound(vec.begin(),vec.end(),x.first) - vec.begin();
    auto R = std::upper_bound(vec.begin(),vec.end(),x.second) - vec.begin() - 1;
    r.push_back(R-L+1);
  }

  return r;
}

#endif
