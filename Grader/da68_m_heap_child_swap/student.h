#include "priority_queue.h"
#include <utility>
#include <queue>
#include <vector>

template <typename T,typename Comp>
void CP::priority_queue<T, Comp>::child_swap(size_t k) {

  std::queue<std::pair<int,int>> qu;
  std::vector<int> vec[65500];
  qu.push({k,0});
  int cur = 1;
  int cnt = 1, mxd = 0;;
  while(!qu.empty()){
    int u = qu.front().first;
    int d = qu.front().second;
    mxd = std::max(mxd,d);
    qu.pop();
    vec[d].push_back(u);
    if(2*u+1 < mSize) qu.push({2*u+1, d+1});
    if(2*u+2 < mSize) qu.push({2*u+2, d+1});
  }

  // for(int i=1;i<=mxd;i++){
  //   for(auto x:vec[i]) std::cout<<x<<' ';
  //   std::cout<<'\n';
  // }

  for(int i=1;i<=mxd;i++){
    for(int j=0;j<vec[i].size()/2;j++){
      // std::cout<<vec[i][j]<<' ';
      std::swap(mData[vec[i][j]], mData[vec[i][vec[i].size()/2 + j]]);
    }
    // std::cout<<'\n';
  }
  return ;
}