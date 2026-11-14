// Your code here

// #include<iostream>

size_t recur(node* n, size_t& mx, KeyT& val){
    size_t l = 0,r = 0;

    if(n->right != NULL) r += recur(n->right,mx,val);
    if(n->left != NULL) l += recur(n->left,mx,val);
    // std::cout<<n->data.first<<' '<<l<<' '<<r<<'\n';

    size_t abs = (l > r ? l-r : r-l);
    if(abs >= mx){
        mx = abs;
        val = n->data.first;
    }

    return (std::max(l,r)) + 1;
}

KeyT getValueOfMostImbalanceNode() {
    size_t mx = 0;
    key_t val = mRoot->data.second;
    recur(mRoot,mx,val);
    return val;
}
