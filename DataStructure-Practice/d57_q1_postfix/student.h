#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>
using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  std::stack<int> val;
  for(auto x:v){
    if(x.first == 1) val.push(x.second);
    else{
      int a = val.top(); val.pop();
      int b = val.top(); val.pop();
      if(x.second == 0) val.push(a+b);
      if(x.second == 1) val.push(b-a);
      if(x.second == 2) val.push(a*b);
      if(x.second == 3) val.push(b/a);
    }
  }
  return val.top();
}

#endif
