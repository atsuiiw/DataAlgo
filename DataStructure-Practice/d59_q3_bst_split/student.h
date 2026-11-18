#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;

  node* it = mRoot;
  node* rCur = NULL; node* rRoot = NULL;
  node* lCur = NULL; node* lRoot = NULL;
  while(it!=NULL){
    if(val <= it->data.first){
      if(rCur == NULL) rRoot = it;
      else rCur->left = it;
      it->parent = rCur;
      rCur = it;
      it = it->left;
    }
    else{
      if(lCur == NULL) lRoot = it;
      else lCur->right = it;
      it->parent = lCur;
      lCur = it;
      it = it->right;
    }
    
  }

  if(rRoot != NULL) rCur->left = NULL;
  if(lRoot != NULL) lCur->right = NULL;

  result.mRoot = rRoot;
  mRoot = lRoot;

  return result;
}

#endif
