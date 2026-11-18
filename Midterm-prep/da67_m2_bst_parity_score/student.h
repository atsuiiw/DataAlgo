#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::parity_score(int d) {
    if(d==0) return 1;
    int ans = 0;
    parity_score_helper(mRoot,d,ans);
    return (ans < 0 ? -ans : ans);
}

template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::parity_score_helper(node *n, int depth, int &parity_score){
    if(n == NULL) return ;
    parity_score += (n->data.first % 2 ? 1 : -1);
    // std::cout<<n->data.first<<' '<<parity_score<<'\n';
    if(depth == 0) return ;
    parity_score_helper(n->left, depth-1, parity_score);
    parity_score_helper(n->right, depth-1, parity_score);
}


#endif
