//
// Created by admin on 2020/7/31.
//

#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H
class btree{
    int key;
    btree *left, *right;
public:
    // constructor
    btree(int k);
    // destructor
    ~btree();
    // deepcopy
    btree (const btree& t);
    // return left tree
    btree* leftTree();
    btree* rightTree();
    // get key
    int getKey();
    // insertion
    void insert(btree*, int);
    // deletion
    // delete a node and all of its subtree if existed
    btree* deletion(btree*, int);

};
void inorder(btree*);
#endif //BTREE_BTREE_H
