#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::stack<std::vector<std::queue<int>>> rev;
    std::stack<std::vector<std::queue<int>>> ans;

    while(!a.empty()){
        auto v = a.top();
        a.pop();
        for(auto& x:v){
            std::queue<int> qu;
            while(!x.empty()){
                qu.push((x.front() == from ? to : x.front()));
                x.pop();
            }
            x = qu;
        }
        rev.push(v);
    }
    while(!rev.empty()){
        ans.push(rev.top());
        rev.pop();
    }
    a = ans;

}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for(auto& x:a){
        auto tmp = x.second;
        std::priority_queue<int> pq;
        while(!tmp.first.empty()){
            // std::cout<<tmp.first.top()<<' ';
            pq.push((tmp.first.top() == from ? to : tmp.first.top()));
            tmp.first.pop();
        }
        if(x.second.second == from) x.second.second = to;
        x.second.first = pq;
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> tmp;
    for(auto x:a){
        // list
        std::list<int> ls = x.first;
        std::replace(ls.begin(),ls.end(),from,to);

        // map
        std::map<int, std::pair<int, string>> mp;
        for(auto& v:x.second){
            int mapKey = v.first;
            std::pair<int,string> mapValue = v.second;
            if(mapKey == from) mapKey = to;
            if(mapValue.first == from) mapValue.first = to;
            mp[mapKey] = mapValue;
        }
        tmp.insert(make_pair(ls,mp));
    }
    a = tmp;
}

#endif
