//
// Created by admin on 2020/7/31.
//

#include "btree.h"
#include <iostream>
#include <list>
#include <queue>
using namespace std;

btree::btree(int k) {
    key = k;
    left = NULL;
    right = NULL;
}

btree::~btree() {
    left = NULL;
    right = NULL;
    delete left;
    delete right;
}

btree::btree(const btree &t) {
    this->key = t.key;
    this->left = t.left;
    this->right = t.right;
}


btree* btree::leftTree() {
    return left;
}

btree* btree::rightTree() {
    return right;
}

void btree::insert(btree *p, int key) {
    queue<btree*> q;
    q.push(p);

    while(!q.empty()){
        btree* temp = q.front();
        q.pop();

        if(!temp->left){
            temp->left = new btree(key);
            break;
        }
        else{
            q.push(temp->left);
        }

        if(!temp->right){
            temp->right = new btree(key);
            break;
        }
        else{
            q.push(temp->right);
        }
    }
}

int btree::getKey() {
    return key;
}

// traverse the tree in inorder way
void inorder(btree* t){
    if(!t){
        return;
    }
    inorder(t->leftTree());
    cout << t->getKey() << " ";
    inorder(t->rightTree());
}
// print the element of a queue
void qPrint(queue<btree*> q){
    if(q.empty()){
        cout << "empty queue!" << endl;
        return;
    }
    for(int i=0; i < q.size(); i++){
        cout << q.front()->getKey() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;
}

btree* btree::deletion(btree* root, int k) {
    queue<btree*> q;
    btree* p = root;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p->key == k){
            if(p==root){
                root = NULL;
            }
            p = NULL;
            delete p;
            return root;
        }
        if(p->left){
            if(p->left->key==k){
                p->left = NULL;
                delete p->left;
                return root;
            }
            q.push(p->left);
        }
        if(p->right){
            if(p->right->key==k){
                p->right = NULL;
                delete p->right;
                return root;
            }
            q.push(p->right);
        }
    }
    return root;
}