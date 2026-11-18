#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
#include<iostream>

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
    // std::cout<<n->data.first<<'\n';
	if(n->left == NULL && n->right == NULL) return 1;
    int L = 1, R = 1;
    if(n->left != NULL) L += my_recur(n->left, aux);
    if(n->right != NULL) R += my_recur(n->right, aux);
    // std::cout<<n->data.first<<' '<<L<<' '<<R<<'\n';
    aux = std::max(aux,L+R-2);
    return std::max(L,R);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
	if(mSize == 0) return -1;
    if(mSize == 1) return 0;
    int ans = 0;
    my_recur(mRoot, ans);
    return ans;
}

#endif
