#ifndef __STUDENT_H_
#define __STUDENT_H_


#include<iostream>
#include<queue>

template <typename KeyT,
typename MappedT,
typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;

  node* lRoot = NULL; node* lLast = NULL;
  node* rRoot = NULL; node* rLast = NULL;

  node* cur = mRoot;

  while(cur!=NULL){
    if(cur->data.first >= val){
      if(rLast == NULL) rRoot = cur;
      else rLast->left = cur;
      cur->parent = rLast;
      rLast = cur;
      cur = cur->left;
    }
    else {
      if(lLast == NULL) lRoot = cur;
      else lLast->right = cur;
      cur->parent = lLast;
      lLast = cur;
      cur = cur->right;
    }
  }

  if(lLast != NULL) lLast->right = NULL;
  if(rLast != NULL) rLast->left = NULL;

  result.mRoot = rRoot;
  mRoot = lRoot;

  return result;
}

#endif
