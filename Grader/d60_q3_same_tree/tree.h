#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class Tree{
    class Node{
        public:
            friend class Tree;
            Node() {data = -1; left = NULL; right = NULL;}
            Node(const int x, Node* left, Node* right) : data(x), left(left), right(right) {}

        protected:
            int data;
            Node* left;
            Node* right;
    };
public:

    Tree() {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree() {
        clear(mRoot);
    }

    void clear(Node*& r) {
        if (!r) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x) {
        insertAt(mRoot, x);
    }
    bool isSameBinaryTree(Tree& t) {
        return isSame(mRoot,t.mRoot);
    }

    bool isSame(Node* a, Node* b){
        if(a->data != b->data) return false;
        bool ch = true;
        if(a->left != NULL){
            if(b->left != NULL) ch &= isSame(a->left,b->left);
            if(b->left == NULL) return false;
        }
        if(a->left == NULL && b->left != NULL) return false;
        if(a->right != NULL){
            if(b->right != NULL) ch &= isSame(a->right,b->right);
            if(b->right == NULL) return false;
        }
        if(a->right == NULL && b->right != NULL) return false;
        return ch;
    }

protected:
    void insertAt(Node*& r, int x) {
        if (!r) {
           r = new Node(x, NULL, NULL);
           mSize++;
           return;
        }
        if (r->data == x) return; // Do nothing
        if (x < r->data) insertAt(r->left, x); else
        insertAt(r->right, x);
    }
    Node* mRoot;
    int mSize;

};

#endif // TREE_H_INCLUDED
