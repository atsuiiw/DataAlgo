#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include<iostream>
#include "map_bst.h"


template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  if(n->left == NULL && n->right == NULL) return 1;
  // std::cout<<(n->data.first)<<' ';
  size_t cnt = 1;
  if(n->left != NULL) cnt += process(n->left);
  if(n->right != NULL) cnt += process(n->right);
  return cnt;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  left.delete_all_nodes(left.mRoot);
  right.delete_all_nodes(right.mRoot);

  left.mSize = mRoot->left==NULL ? 0 : process(mRoot->left);
  left.mRoot = mRoot->left;
  mRoot->left = NULL;
  
  right.mSize = mRoot->right==NULL ? 0 : process(mRoot->right);
  right.mRoot = mRoot->right;
  mRoot->right = NULL;
  
  mSize = 1;
  return mRoot->data;
}

#endif

