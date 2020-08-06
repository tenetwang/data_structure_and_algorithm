#include <iostream>
#include "./src/btree/btree.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    btree root(10);
    root.insert(&root, 11);
    root.insert(&root, 12);
    root.insert(&root, 13);
    inorder(&root);
    cout << endl;
    btree* r = root.deletion(&root, 10);
    inorder(r);
    cout << endl;

    cout << "done" << endl;

    return 0;
}
