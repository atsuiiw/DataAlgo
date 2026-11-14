#ifndef __STUDENT_H_
#define __STUDENT_H_

// You may include library here
#include "map_bst.h"
#include<math.h>

template <typename KeyT, 
          typename MappedT, 
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::recursive1(node* n) const 
{
    size_t L = 0, R = 0;
    if(n->right != NULL) R = recursive1(n->right);
    if(n->left != NULL) L = recursive1(n->left);
    return std::max(L,R) + 1;
}

template <typename KeyT, 
          typename MappedT, 
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::recursive2(node* n, std::size_t i, std::vector<KeyT>& v) const 
{
    v[i] = n->data.first;

    // going into it
    if(n->left != NULL) recursive2(n->left,2*i+1,v);
    if(n->right != NULL) recursive2(n->right,2*i+2,v);
    
}

template <typename KeyT, 
          typename MappedT, 
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT, MappedT, CompareT>::flatten() const 
{
    if(mSize==0) return {};
    size_t N = recursive1(mRoot);
    std::vector<KeyT> vec(std::pow(2,N)-1);
    recursive2(mRoot,0,vec);
    return vec;
}

#endif
