
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::recursive(node* n,CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // You may need this function
    // node n, map::iterator p, q
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::lca(CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // Write your code here
    // map::iterator p,q

    KeyT a = p->first;
    KeyT b = q->second;
    node* it = mRoot;

    while(it != NULL){
        KeyT k = it->data.first;
        if(mLess(a,k) && mLess(b,k)) it = it->left;
        else if(mLess(k,a) && mLess(k,b)) it = it->right;
        else return it;
    }

    // while(it != mRoot){
    //     it = it.ptr->parent;
    // }
    return NULL;
}

#endif
