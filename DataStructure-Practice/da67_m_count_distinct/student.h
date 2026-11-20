#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include<unordered_map>

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b)
{
    std::unordered_map<T,bool> mp;
    for(auto i=a;i!=b;i++){
        if(mp.find(*i) == mp.end()) mp[*i] = true;
    }
    return mp.size();
}

#endif