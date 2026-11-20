#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  if(n->left == NULL && n->right == NULL) return 1;
  int cnt = 1;
  if(n->left != NULL) cnt += process(n->left);
  if(n->right != NULL) cnt += process(n->right);
  return cnt;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here

  left.clear();
  right.clear();

  node* l = mRoot->left;
  node* r = mRoot->right;

  if(mRoot->left != NULL){
    l->parent = NULL;
    left.mRoot = l;
    left.mSize = process(left.mRoot);
  }
  else{
    left.mSize = 0;
  }
  if(mRoot->right != NULL){
    r->parent = NULL;
    right.mRoot = r;
    right.mSize = process(right.mRoot);
  }
  else{
    right.mSize = 0;
  }
  
  mRoot->left = NULL;
  mRoot->right = NULL;
  mSize = 1;

  return mRoot->data;
}

#endif

